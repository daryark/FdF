/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:15:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/10 19:24:16 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	calc_zoom(t_fdf *fdf)
{
	if ((WIN_WIDTH - MENU_WIDTH) / fdf->real_w < WIN_HEIGHT / fdf->real_h)
		fdf->zoom  = ((WIN_WIDTH - MENU_WIDTH) / fdf->real_w);
	else
		fdf->zoom = WIN_HEIGHT / fdf->real_h;
}

void	calc_offset(t_fdf *fdf, int x_low, int y_low)
{
	fdf->offset_x = ((WIN_WIDTH - MENU_WIDTH) / 2) - ((fdf->real_w - 1) / 2) + MENU_WIDTH;
	fdf->offset_y = (WIN_HEIGHT / 2) - ((fdf->real_h - 1) / 2);
	if (x_low < 0)
		fdf->offset_x += ft_abs(x_low);
	if (y_low < 0)
		fdf->offset_y += ft_abs(y_low);
}

void    isometric(int *x, int *y, int z)
{
	float a;
	
	a = *x;
    *x = (a - *y) * cos(0.523599);
    *y = (a + *y) * sin(0.523599) - z;
	
}
//check if this func is actually used ??
void	transform_point(t_map *a, t_fdf *fdf)
{
	make_zoom(a, fdf->zoom);
	isometric(&a->x, &a->y, a->val);
	set_offset(a, fdf->offset_x, fdf->offset_y);
}
// void	real_map_size(t_fdf *fdf)
// {
// 	int j;
// 	int i;
// 	int	x_low = INT_MAX;
// 	int y_low = INT_MAX;
// 	int x_high = INT_MIN;
// 	int y_high = INT_MIN;
	
// 	i = -1;
// 	while (i < fdf->height)
// 	{
// 		j = -1;
// 		while (++j < fdf->width)
// 		{
// 			if (fdf->map[i][j].x < x_low)
// 				x_low = fdf->map[i][j].x;
// 			else if (fdf->map[i][j].x > x_high)
// 				x_high = fdf->map[i][j].x;
// 			if (fdf->map[i][j].y < y_low)
// 				y_low = fdf->map[i][j].y;
// 			else if (fdf->map[i][j].y > y_high)
// 				y_high = fdf->map[i][j].y;
// 		}
// 	}
// 	fdf->real_w = (x_high - x_low);
// 	fdf->real_h = (y_high - y_low);
// }

void	center_map(t_fdf *fdf)
{
	int	x_low = INT_MAX;
	int y_low = INT_MAX;
	int x_high = INT_MIN;
	int y_high = INT_MIN;

	int j;
	int i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (fdf->map[i][j].x < x_low)
				x_low = fdf->map[i][j].x;
			else if (fdf->map[i][j].x > x_high)
				x_high = fdf->map[i][j].x;
			if (fdf->map[i][j].y < y_low)
				y_low = fdf->map[i][j].y;
			else if (fdf->map[i][j].y > y_high)
				y_high = fdf->map[i][j].y;
			j++;
		}
		i++;
	}
	fdf->real_w = (x_high - x_low);
	fdf->real_h = (y_high - y_low);
	calc_offset(fdf, x_low, y_low);
	i = -1;
	check_corners_red(fdf, x_low, y_low, x_high, y_high);
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
			set_offset(&fdf->map[i][j], fdf->offset_x, fdf->offset_y);
	}
}
