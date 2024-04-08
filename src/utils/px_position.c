/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:15:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/09 01:00:56 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	calc_zoom(t_fdf *fdf)
{
	if ((WIN_WIDTH - MENU_WIDTH) / fdf->width < WIN_HEIGHT / fdf->height)
		fdf->zoom  = ((WIN_WIDTH - MENU_WIDTH) / fdf->width);
	else
		fdf->zoom = WIN_HEIGHT / fdf->height;
}

void	make_zoom(t_map *point, int zoom)
{
	point->x *= zoom;
	point->y *= zoom;
}

void	calc_offset(t_fdf *fdf)
{
	fdf->offset_x = ((WIN_WIDTH - MENU_WIDTH) / 2) - \
	(((fdf->width - 1) * fdf->zoom) / 2) + MENU_WIDTH;
	fdf->offset_y = ((WIN_HEIGHT) / 2) - ((fdf->height - 1) * fdf->zoom) / 2; 
}

void	set_offset(t_map *point, int offset_x, int offset_y)
{
	point->x += offset_x;
	point->y += offset_y;
}

void    isometric(int *x, int *y, int z)
{
	float a;
	
	//0.523599
	a = *x;
	
    *x = (a - *y) * cos(0.523599);
    *y = (a + *y) * sin(0.523599) - z;
}

void	transform_point(t_map *a, t_fdf *fdf)
{
	make_zoom(a, fdf->zoom);
	isometric(&a->x, &a->y, a->val);
	set_offset(a, fdf->offset_x, fdf->offset_y);
}

// void	center_map(t_fdf *fdf)
// {
// 	int	x_low = INT_MAX;
// 	int y_low = INT_MAX;
// 	int x_high = INT_MIN;
// 	int y_high = INT_MIN;

// 	int j;
// 	int i = 0;

// 	while (i < fdf->height)
// 	{
// 		j = 0;
// 		while (j < fdf->width)
// 		{
// 			fdf->map[i][j].x -= fdf->offset_x;
// 			fdf->map[i][j].y -= fdf->offset_y;
// 			if (fdf->map[i][j].x < x_low)
// 				x_low = fdf->map[i][j].x;
// 			else if (fdf->map[i][j].x > x_high)
// 				x_high = fdf->map[i][j].x;
// 			if (fdf->map[i][j].y < y_low)
// 				y_low = fdf->map[i][j].y;
// 			else if (fdf->map[i][j].y > y_high)
// 				y_high = fdf->map[i][j].y;
// 			j++;
// 		}
// 		i++;
// 	}
// 	int wid_x = (x_high - x_low);
// 	int hei_y = (y_high - y_low);

// 	fdf->offset_x = ((WIN_WIDTH - MENU_WIDTH) / 2) - \
// 	(((wid_x - 1) * fdf->zoom) / 2) + MENU_WIDTH;
// 	fdf->offset_y = ((WIN_HEIGHT) / 2) - ((hei_y - 1) * fdf->zoom) / 2;
// }