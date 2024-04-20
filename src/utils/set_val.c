/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:34:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/20 18:47:40 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	make_zoom(t_map *point, float zoom)
{
	point->x *= zoom;
	point->y *= zoom;
	point->val *= zoom;
}

void	set_offset(t_map *point, int offset_x, int offset_y)
{
	point->x += offset_x;
	point->y += offset_y;
}

void	set_default_values(t_fdf *fdf)
{
	fdf->height = 0;
	fdf->width = 0;
	fdf->zoom = 50.0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->slope = 0.0;
	fdf->map = NULL;
	fdf->map_orig = NULL;
	fdf->edge = (t_edge){.real_h = 0, .real_w = 0, .x_high = INT_MIN, \
		.x_low = INT_MAX, .y_high = INT_MIN, .y_low = INT_MAX, \
		.z_high = INT_MIN, .z_low = INT_MAX};
	fdf->img = NULL;
	fdf->menu = NULL;
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->err = 0;
	fdf->z_coef = 1;
	fdf->angle_x = 30;
	fdf->angle_y = 330;
	fdf->angle_z = 30;
	fdf->pre_event = 0; //!
	fdf->pressed = (t_pressed){.x = 0, .y = 0, .ctrl_l = 0, \
		.down = 0, .up = 0, .left = 0, .right = 0, .plus = 0, .minus = 0};
}

void	reset_edge(t_edge *p)
{
	p->x_low = INT_MAX;
	p->y_low = INT_MAX;
	p->z_low = INT_MAX;
	p->x_high = INT_MIN;
	p->y_high = INT_MIN;
	p->z_high = INT_MIN;
	p->real_w = 0;
	p->real_h = 0;
}

void	reset_map(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			fdf->map[i][j].color = fdf->map_orig[i][j].color;
			fdf->map[i][j].val = fdf->map_orig[i][j].val;
			fdf->map[i][j].x = fdf->map_orig[i][j].x;
			fdf->map[i][j].y = fdf->map_orig[i][j].y;
		}
	}
}
