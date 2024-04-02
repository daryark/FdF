/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 03:40:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/03 00:12:32 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

typedef struct s_color {
    int red;
    int green;
    int blue;
} t_color;

void	calc_px_position(t_map *point, int scale)
{
	point->x = point->x * scale + 220;
	point->y = point->y * scale + 20;
}

// potentially 200 is enough for menu bar on left side
// and 40 - is for 20 pixels from each side as a border
//*add adjustment of the map to the center location ??
//*or just leave with the biggest possible scale ?
static void	adjust_map_to_window(t_fdf *fdf)
{
	int	distance;
	int	i;
	int	j;

	distance = 0;
	if ((WIN_WIDTH - 240) / fdf->width < (WIN_HEIGHT - 40) / fdf->height)
		distance  = (WIN_WIDTH - 240) / fdf->width;
	else
		distance = (WIN_HEIGHT - 40) / fdf->height;
	ft_printf(GREEN "distance: %d\n"RE, distance); //just printing stuff
	i = -1; 
	print_map(fdf, 1); 
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
			calc_px_position(&fdf->map[i][j], distance);
	}
	print_map(fdf, 1); 
}

void	show_in_window(t_fdf *fdf)
{
	t_img	img;
	t_img   menu_bar;

	fdf->img = &img;
	fdf->menu_bar = &menu_bar;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	fdf->img->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bits_per_pixel, &fdf->img->line_length, &fdf->img->endian);
	//*calculate real values of the coordinates with the  zoom and positioning adjustment
	adjust_map_to_window(fdf); //*write the function that zoom the map and center it.
	img_put(fdf);
	menu_bar_put(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->menu_bar->img, 0, 0);
	mlx_string_put(fdf->mlx, fdf->window, 150, 30, 0xffffff, "MENU BAR");
	mlx_loop(fdf->mlx);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	mlx_destroy_image(fdf->mlx, fdf->menu_bar->img);
	mlx_destroy_window(fdf->mlx, fdf->window);
}

// go to destination address(start/left upper corner 0,0) and move it to the needed pixel:
//go through amount of rows before the needed line + go to needed pixel inside line
//color the needed pixel with the dot - part of the line
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void	draw_lines_random(t_data *img)
// {
	// int	i;
	// int	j;

	// i = 200;
	// while (i++ < 600)
	// 	my_mlx_pixel_put(img, 10 + i, 5+i, 0x0099FF); //blue
	// i = 200;
	// while (i++ < 600)
	// 	my_mlx_pixel_put(img, 5 + i, 10+i, 0xFF5500); //red
	// i = 800;
	// j = 200;
	// while (i-- > 200 && j++ < 1000)
	// 	my_mlx_pixel_put(img, i, j, 0x99FF99); //green
	// i = 600;
	// j = 200;
	// while (i-- > 200 && j++ < 600)
	// 	my_mlx_pixel_put(img, i - 5, j + 5, 0xff0000); //yellow
	// i = 600;
	// while (i-- > 0)
	// 	my_mlx_pixel_put(img, i - 5, 400, 0xffff00); //horizontal
	// i = 600;
	// while (i-- > 0)
	// 	my_mlx_pixel_put(img, 400, i+5, 0xffff00); //vertical
// }


// t_color	interpolate_color(t_color start, t_color end, float t)
// {
//     t_color result;
//     result.red = start.red + (int)((end.red - start.red) * t);
//     result.green = start.green + (int)((end.green - start.green) * t);
//     result.blue = start.blue + (int)((end.blue - start.blue) * t);
//     return result;
// }

// void draw_gradient_line(int x0, int y0, int x1, int y1, t_color start_color, t_color end_color, t_data *img)
// {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int steps = dx > dy ? dx : dy;

//     float x_increment = (float)(x1 - x0) / steps;
//     float y_increment = (float)(y1 - y0) / steps;
//     float color_increment = 1.0 / steps;

//     float x = x0;
//     float y = y0;
//     float t = 0.0;

//     for (int i = 0; i <= steps; i++) {
//         t_color color = interpolate_color(start_color, end_color, t);
//         int color_hex = (color.red << 16) | (color.green << 8) | color.blue;
//         my_mlx_pixel_put(img, (int)x, (int)y, color_hex);
//         x += x_increment;
//         y += y_increment;
//         t += color_increment;
//     }
// }
