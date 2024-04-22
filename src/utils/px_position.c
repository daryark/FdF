/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:15:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/23 01:17:07 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	adjust_zoom(t_fdf *fdf)
{
	float	potential_zoom_x;
	float	potential_zoom_y;

	find_map_edges(fdf);
	potential_zoom_x = (float)(WIN_W - PADDING * 2 - MENU_W) / \
	(float)fdf->edge.real_w;
	potential_zoom_y = (float)(WIN_H - PADDING * 2) / \
	(float)fdf->edge.real_h;
	if (potential_zoom_x < potential_zoom_y)
		fdf->zoom *= potential_zoom_x;
	else
		fdf->zoom *= potential_zoom_y;
	if (fdf->zoom < 0)
	{
		ft_putendl_fd("Error calculating zoom", 2);
		clean_all(fdf);
		exit(EXIT_FAILURE);
	}
}

int	find_mid_z(t_fdf *fdf)
{
	int	i;
	int	j;
	int	max_val;
	int	min_val;
	// int	mid;

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
	printf("minz: %d, maxz: %d\n", min_val, max_val);
	return ((max_val + min_val)/2*fdf->z_coef);
}
static t_map point(t_map p)
{
	return (p);
}
void	find_center(t_fdf *fdf)
{
	t_map ps;

	ps = point((t_map){.x = (fdf->width / 2), .y = (fdf->height / 2), \
		.val = find_mid_z(fdf), .color = 0xff0000});
	make_zoom(&ps, fdf->zoom);
	printf("zoom: %f\n", fdf->zoom);
	printf("w: %d, h: %d\n", fdf->width, fdf->height);
	printf("x: %f, y: %f, z:%f\n", ps.x, ps.y, ps.val);
	do_isometric(&ps.x, &ps.y, &ps.val, fdf);
	fdf->edge.cx = ps.x;
	fdf->edge.cy = ps.y;
}

void	calc_offset(t_fdf *fdf)
{
	find_map_edges(fdf);
	find_center(fdf);
	//1420 - 20 - 350 / 2	- cx + 350 + 10
	//525	- cx + 350 +  10;
	fdf->offset_x = ((WIN_W - PADDING*2 - MENU_W) / 2) - fdf->edge.cx + MENU_W + PADDING;
	// 640 - cy + 10;
	fdf->offset_y = ((WIN_H - PADDING*2)/ 2) - fdf->edge.cy + PADDING;
}

void	transform_map(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			fdf->map[i][j].val *= fdf->z_coef;
			make_zoom(&fdf->map[i][j], fdf->zoom);
			do_isometric(&fdf->map[i][j].x, &fdf->map[i][j].y, \
				&fdf->map[i][j].val, fdf);
		}
	}
}

void	zoom_map_to_win_size(t_fdf *fdf)
{
	adjust_zoom(fdf);
	reset_map(fdf);
	transform_map(fdf);
}

void	center_map(t_fdf *fdf)
{
	// (void)fdf;
	// // find_center(fdf);
	int	i;
	int	j;

	calc_offset(fdf);
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
			set_offset(&fdf->map[i][j], (fdf->offset_x + fdf->shift_x), \
				(fdf->offset_y + fdf->shift_y));
	}
}
