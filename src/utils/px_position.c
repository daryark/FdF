/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:15:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/23 14:58:55 by dyarkovs         ###   ########.fr       */
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

void	transform_point(t_map *p, t_fdf *fdf)
{
	p->val *= fdf->z_coef;
	make_zoom(p, fdf->zoom);
	do_isometric(p, fdf);
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
			transform_point(&fdf->map[i][j], fdf);
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
	int	i;
	int	j;

	calc_offset(fdf);
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
			set_offset(&fdf->map[i][j], fdf);
	}
}
