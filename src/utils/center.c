/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:39:26 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/23 16:56:30 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	map_z_height(t_fdf *fdf)
{
	int	i;
	int	j;
	int	max_val;
	int	min_val;

	max_val = INT_MIN;
	min_val = INT_MAX;
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			if (max_val < fdf->map_orig[i][j].val)
				max_val = fdf->map_orig[i][j].val;
			if (min_val > fdf->map_orig[i][j].val)
				min_val = fdf->map_orig[i][j].val;
		}
	}
	fdf->zheight = (max_val + min_val);
}

void	find_center(t_fdf *fdf)
{
	t_map	ps;

	ps = (t_map){.x = (fdf->width / 2), .y = (fdf->height / 2), \
		.val = fdf->zheight / 2, .color = 0xff0000};
	transform_point(&ps, fdf);
	fdf->cx = ps.x;
	fdf->cy = ps.y;
}

void	find_map_edges(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	reset_edge(&fdf->edge);
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			min_p(&fdf->map[i][j], &fdf->edge);
			max_p(&fdf->map[i][j], &fdf->edge);
		}
	}
	fdf->edge.real_w = fdf->edge.x_high - fdf->edge.x_low;
	fdf->edge.real_h = fdf->edge.y_high - fdf->edge.y_low;
}

void	calc_offset(t_fdf *fdf)
{
	find_center(fdf);
	fdf->offset_x = ((WIN_W - PADDING * 2 - MENU_W) / 2) \
	- fdf->cx + MENU_W + PADDING;
	fdf->offset_y = ((WIN_H - PADDING * 2) / 2) - fdf->cy \
	+ PADDING;
}
