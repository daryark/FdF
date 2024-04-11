/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:15:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/11 02:14:07 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	calc_zoom(t_fdf *fdf)
{
	int	potential_zoom_x;
	int	potential_zoom_y;

	potential_zoom_x = (WIN_WIDTH - MENU_WIDTH) / fdf->real_w;
	potential_zoom_y = WIN_HEIGHT / fdf->real_h;
	if (potential_zoom_x <= 0 || potential_zoom_y <= 0)
		fdf->zoom = 1;
	else if (potential_zoom_x < potential_zoom_y)
		fdf->zoom  = potential_zoom_x;
	else
		fdf->zoom = potential_zoom_y;
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

void	transform_map(t_fdf *fdf)
{
	int	i;
	int	j;

	// print_map(fdf, 0);
	// print_map(fdf, 1);
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			make_zoom(&fdf->map[i][j], fdf->zoom);
			do_isometric(&fdf->map[i][j].x, &fdf->map[i][j].y, fdf->map[i][j].val);
			// set_offset(a, fdf->offset_x, fdf->offset_y);
		}
	}
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
	check_corners_red(fdf, x_low, y_low, x_high, y_high); //just print helper, delete later
	i = -1;
	// calc_zoom(fdf);
	// ft_printf("zoom available: %d\n", fdf->zoom);
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			// make_zoom(&fdf->map[i][j], fdf->zoom);
			set_offset(&fdf->map[i][j], fdf->offset_x, fdf->offset_y);
		}
	}
}
