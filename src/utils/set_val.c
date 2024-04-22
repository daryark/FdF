/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:34:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/23 01:31:15 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	make_zoom(t_map *point, float zoom)
{
	point->x *= zoom;
	point->y *= zoom;
	point->val *= zoom;
}

void	set_offset(t_map *point, t_fdf *fdf)
{
	point->x += (fdf->offset_x + fdf->shift_x);
	point->y += (fdf->offset_y + fdf->shift_y);
}

void	initialize_pointers_null(t_fdf *fdf)
{
	fdf->map = NULL;
	fdf->map_orig = NULL;
	fdf->img = NULL;
	fdf->menu = NULL;
	fdf->mlx = NULL;
	fdf->window = NULL;
}

void	set_default_values(t_fdf *fdf)
{
	fdf->height = 0;
	fdf->width = 0;
	fdf->err = 0;
	fdf->edge = (t_edge){.real_h = 0, .real_w = 0, .x_high = INT_MIN, \
		.x_low = INT_MAX, .y_high = INT_MIN, .y_low = INT_MAX, \
		.z_high = INT_MIN, .z_low = INT_MAX};
	fdf->pressed = (t_pressed){.x = 0, .y = 0, .ctrl_l = 0, \
		.down = 0, .up = 0, .left = 0, .right = 0, .plus = 0, .minus = 0};
	reset_screen_values(fdf);
}

void	reset_screen_values(t_fdf *fdf)
{
	fdf->zoom = 50.0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->slope = 0.0;
	fdf->z_coef = 1;
	fdf->angle_x = 0;
	fdf->angle_y = 0;
	fdf->angle_z = 0;
}

void	reset_edge(t_edge *p)
{
	p->x_low = INT_MAX;
	p->y_low = INT_MAX;
	p->z_low = INT_MAX;
	p->x_high = INT_MIN;
	p->y_high = INT_MIN;
	p->z_high = INT_MIN;
	p->cx = 0;
	p->cy = 0;
	p->cz = 0;
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
