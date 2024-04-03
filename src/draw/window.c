/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 03:40:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/03 20:57:42 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

typedef struct s_color {
    int red;
    int green;
    int blue;
} t_color;

// go to destination address(start/left upper corner 0,0) and move it to the needed pixel:
//go through amount of rows before the needed line + go to needed pixel inside line
//color the needed pixel with the dot - part of the line
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	px_real_position(t_map *point, int zoom)
{
	point->x = point->x * zoom + 20 + (WIN_WIDTH / 4);
	point->y = point->y * zoom + 20;
}

// potentially 200 is enough for menu bar on left side
// and 40 - is for 20 pixels from each side as a border
//!add adjustment of the map to the center location ??
//*or just leave with the biggest possible scale ?
static void	adjust_map_to_window(t_fdf *fdf)
{
	int	i;
	int	j;

	if ((WIN_WIDTH - 40 - (WIN_WIDTH / 4)) / fdf->width < (WIN_HEIGHT - 40) / fdf->height)
		fdf->zoom  = (WIN_WIDTH - 40 - (WIN_WIDTH / 4)) / fdf->width;
	else
		fdf->zoom = (WIN_HEIGHT - 40) / fdf->height;
	ft_printf(GREEN "fdf->zoom: %d\n"RE, fdf->zoom); //just printing stuff
	i = -1; 
	print_map(fdf, 1); 
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
			px_real_position(&fdf->map[i][j], fdf->zoom);
	}
	print_map(fdf, 1);
}

void    img_put(t_fdf *fdf)
{
    int i;
    int j;

    fdf->img->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
    fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bpp, &fdf->img->len, &fdf->img->endian);
	adjust_map_to_window(fdf); //*write the function that zoom the map and center it.
    i = -1;
    while (++i < fdf->height)
    {
        j = -1;
        while (++j < fdf->width)
        {
            if (j + 1 < fdf->width)
                 draw_line_algorithm(fdf->map[i][j], fdf->map[i][j + 1], fdf);
            if (i + 1 < fdf->height)
                 draw_line_algorithm(fdf->map[i][j], fdf->map[i + 1][j], fdf);
        }
    }
}

void	show_in_window(t_fdf *fdf)
{
	t_img	img;
	t_img   menu;

	fdf->img = &img;
	fdf->menu = &menu;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	img_put(fdf);
	menu_put(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->menu->img, 0, 0);
	menu_text_put(fdf);
	mlx_loop(fdf->mlx);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	mlx_destroy_image(fdf->mlx, fdf->menu->img);
	mlx_destroy_window(fdf->mlx, fdf->window);
}

