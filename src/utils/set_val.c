/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:34:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/19 22:18:53 by dyarkovs         ###   ########.fr       */
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

int	set_default_values(t_fdf *fdf)
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
	fdf->corner = malloc(sizeof(t_corner));
	if (is_alloc_err_cleaner(fdf->corner, fdf))
		return (1);
	fdf->img = NULL;
	fdf->menu = NULL;
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->err = 0;
	fdf->pre_event = 0;
	fdf->z_coef = 1;
	fdf->prev_mv = 0;
	fdf->angle_x = 30;
	fdf->angle_y = 330;
	fdf->angle_z = 30;
	return (0);
}

void	reset_corner(t_corner *p)
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
