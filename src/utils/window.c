/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 03:40:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/29 21:30:48 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

typedef struct s_color {
    int red;
    int green;
    int blue;
} t_color;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_circle(int x_center, int y_center, int radius,t_data *img);
void	draw_lines_random(t_data *img);
void draw_gradient_line(int x0, int y0, int x1, int y1, t_color start_color, t_color end_color, t_data *img);
void	draw_gradient(int x0, int y0, int x1, int y1, t_color start_color, t_color end_color, t_data *img, int range);
void	draw_gradient_horizontal(int x0, int y0, int x1, int y1, t_color start_color, t_color end_color, t_data *img, int range);
void	draw_gradient_triangle(int x0, int y0, int x1, int y1, t_color start_color, t_color end_color, t_data *img, int range);

void	show_in_window(t_fdf *fdf)
{
	t_data	img;

	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
	{
		//error return
	}
	fdf->window = mlx_new_window(fdf->mlx, 1200, 1000, "FdF");
	img.img = mlx_new_image(fdf->mlx, 1200, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_gradient(0, 0, 0, 799, (t_color){15,133,44}, (t_color){3,50,15}, &img, 800);
	draw_gradient_horizontal(200, 200, 200, 300, (t_color){225,226,20}, (t_color){15,27,133}, &img, 100);
	draw_gradient_triangle(300, 300, 400, 300, (t_color){15,27,133}, (t_color){225,226,20}, &img, 100);
	draw_gradient(100, 100, 100, 200, (t_color){255, 0, 0}, (t_color){0, 0, 255}, &img, 100);
	draw_lines_random(&img);
	draw_circle(0, 500, 300, &img);
	draw_gradient(-100, 500, 200, -200, (t_color){255, 0, 0}, (t_color){0, 0, 255}, &img, 100);
	mlx_put_image_to_window(fdf->mlx, fdf->window, img.img, 0, 0);
	mlx_loop(fdf->mlx);
	mlx_destroy_image(fdf->mlx, fdf->img->img);
	mlx_destroy_window(fdf->mlx, fdf->window);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_lines_random(t_data *img)
{
	int	i;
	int	j;

	i = 200;
	while (i++ < 600)
		my_mlx_pixel_put(img, 10 + i, 5+i, 0x0099FF); //blue
	i = 200;
	while (i++ < 600)
		my_mlx_pixel_put(img, 5 + i, 10+i, 0xFF5500); //red
	i = 800;
	j = 200;
	while (i-- > 200 && j++ < 1000)
		my_mlx_pixel_put(img, i - 200, i - j, 0x99FF99); //green
	i = 600;
	j = 200;
	while (i-- > 200 && j++ < 600)
		my_mlx_pixel_put(img, i - 5, j + 5, 0xff0000); //yellow
	i = 600;
	while (i-- > 0)
		my_mlx_pixel_put(img, i - 5, 400, 0xffff00); //horizontal
	i = 600;
	while (i-- > 0)
		my_mlx_pixel_put(img, 400, i+5, 0xffff00); //vertical
}

void	draw_circle(int x_center, int y_center, int radius,t_data *img)
{
    int x = radius;
    int y = 0;
    int radius_error = 1 - x;

    while (x >= y) {
        my_mlx_pixel_put(img, x + x_center+200, y + y_center+90, 0xFFC0CB);
        my_mlx_pixel_put(img, y + x_center+200, x + y_center+90, 0xFFC0CB);
        my_mlx_pixel_put(img, -x + x_center-200, y + y_center-90, 0xFFC0CB);
        my_mlx_pixel_put(img, -y + x_center-200, x + y_center-90, 0xFFC0CB);
        my_mlx_pixel_put(img, -x + x_center-200, -y + y_center-90, 0xFFC0CB);
        my_mlx_pixel_put(img, -y + x_center-200, -x + y_center-90, 0xFFC0CB);
        my_mlx_pixel_put(img, x + x_center+200, -y + y_center+90, 0xFFC0CB);
        my_mlx_pixel_put(img, y + x_center+200, -x + y_center+90, 0xFFC0CB);
        y++;

        if (radius_error < 0)
            radius_error += 2 * y + 1;
        else {
            x--;
            radius_error += 2 * (y - x + 1);
        }
    }
}

t_color	interpolate_color(t_color start, t_color end, float t)
{
    t_color result;
    result.red = start.red + (int)((end.red - start.red) * t);
    result.green = start.green + (int)((end.green - start.green) * t);
    result.blue = start.blue + (int)((end.blue - start.blue) * t);
    return result;
}

void draw_gradient_line(int x0, int y0, int x1, int y1, t_color start_color, t_color end_color, t_data *img)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int steps = dx > dy ? dx : dy;

    float x_increment = (float)(x1 - x0) / steps;
    float y_increment = (float)(y1 - y0) / steps;
    float color_increment = 1.0 / steps;

    float x = x0;
    float y = y0;
    float t = 0.0;

    for (int i = 0; i <= steps; i++) {
        t_color color = interpolate_color(start_color, end_color, t);
        int color_hex = (color.red << 16) | (color.green << 8) | color.blue;
        my_mlx_pixel_put(img, (int)x, (int)y, color_hex);
        x += x_increment;
        y += y_increment;
        t += color_increment;
    }
}

void	draw_gradient(int x0, int y0, int x1, int y1, t_color start_color, t_color end_color, t_data *img, int range)
{
	int	i;

	i = -1;
	while (++i < range)
		draw_gradient_line(x0+i, y0, x1+i, y1, start_color, end_color, img);
}

void	draw_gradient_horizontal(int x0, int y0, int x1, int y1, t_color start_color, t_color end_color, t_data *img, int range)
{
	int	i;

	i = -1;
	while (++i < range)
		draw_gradient_line(y0, x0+i, y1, x1+i, start_color, end_color, img);
}

void	draw_gradient_triangle(int x0, int y0, int x1, int y1, t_color start_color, t_color end_color, t_data *img, int range)
{
	int	i;

	i = -1;
	while (++i < range)
		draw_gradient_line(x0, y0+i, x1, y1, start_color, end_color, img);
}
// void	read_file(char	*file)
// {
// 	int		fd;
// 	char	*n_l;
// 	fd = open("test_maps/42.fdf", O_RDONLY);
// 	while (1)
// 	{
// 		n_l = get_next_line(fd);
// 		if (!n_l)
// 			break;
// 		printf("%s", n_l);
// 	}
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// int i = 0;
	// while (i++ < 100)
	// 	my_mlx_pixel_put(&img, 10 + i, 5+i, 0x0099FF99);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
// }