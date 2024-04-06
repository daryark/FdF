/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:15:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/06 04:34:36 by dyarkovs         ###   ########.fr       */
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

	a = *x;
    *x = (*x - *y) * cos(0.523599);
    *y = (a+ *y) * sin(0.523599) - z;
}