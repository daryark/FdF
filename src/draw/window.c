/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 03:40:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/11 02:45:09 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// go to first window px and move it to px: pass rows before
// needed line +  pxs' inside line. fill the px with color;
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void    img_put(t_fdf *fdf)
{
    int i; 
    int j;

    fdf->img->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
    fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bpp, &fdf->img->len, &fdf->img->endian);
    print_center_vector_helper(fdf); //just printing stuff, remove later;
    i = -1;
    transform_map(fdf);
    center_map(fdf);
    while (++i < fdf->height)
    {
        j = -1;
        while (++j < fdf->width)
        {
            if (j + 1 < fdf->width 
                && fdf->map[i][j].color != (unsigned int)(-1)
                && fdf->map[i][j + 1].color != (unsigned int)(-1))
                    draw_line_algorithm(fdf->map[i][j], fdf->map[i][j + 1], fdf);
            if (i + 1 < fdf->height
                && fdf->map[i][j].color != (unsigned int)(-1)
                && fdf->map[i + 1][j].color != (unsigned int)(-1))
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
    if(!fdf->mlx)
    {
        free_map(fdf);
        return ;
    }
	fdf->window = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	img_put(fdf);
	menu_put(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->menu->img, 0, 0);
	menu_text_put(fdf);
	// mlx_mouse_hook(fdf->window, mouse_hook, fdf);
	mlx_key_hook(fdf->window, key_hook, fdf);
    mlx_loop(fdf->mlx);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	mlx_destroy_image(fdf->mlx, fdf->menu->img);
	mlx_destroy_window(fdf->mlx, fdf->window);
    if (fdf->map != NULL)
    free_map(fdf);
}

