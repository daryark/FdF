/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:34:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/25 09:31:32 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	initialize_pointers_null(t_fdf *fdf)
{
	fdf->map = NULL;
	fdf->map_orig = NULL;
	fdf->img = NULL;
	fdf->menu = NULL;
	fdf->mlx = NULL;
	fdf->window = NULL;
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
	fdf->angle_x = 30;
	fdf->angle_y = 330;
	fdf->angle_z = 30;
}

void	set_default_values(t_fdf *fdf)
{
	fdf->width = 0;
	fdf->height = 0;
	fdf->zheight = 0;
	fdf->cx = 0;
	fdf->cy = 0;
	reset_edge(&fdf->edge);
	fdf->pressed = (t_pressed){.x = 0, .y = 0, .ctrl_l = 0, .vector = 0, \
		.down = 0, .up = 0, .left = 0, .right = 0, .plus = 0, .minus = 0, \
		.ortho = 0, .iso = 1};
	reset_screen_values(fdf);
}

void	reset_edge(t_edge *p)
{
	p->x_low = INT_MAX;
	p->y_low = INT_MAX;
	p->x_high = INT_MIN;
	p->y_high = INT_MIN;
	p->real_w = 0;
	p->real_h = 0;
}
