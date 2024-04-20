/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:15:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/20 17:12:54 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	adjust_zoom(t_fdf *fdf)
{
	float	potential_zoom_x;
	float	potential_zoom_y;

	find_map_edges(fdf);
	potential_zoom_x = (float)(WIN_W - 20 - MENU_W) / \
		(float)fdf->edge.real_w;
	potential_zoom_y = (float)(WIN_H - 20) / (float)fdf->edge.real_h;
	if (potential_zoom_x < potential_zoom_y)
		fdf->zoom *= potential_zoom_x;
	else
		fdf->zoom *= potential_zoom_y;
	if (fdf->zoom < 0)
	{
		ft_putendl_fd("Error calculating zoom", 2);
		clean_all(fdf);
		return ;
	}
	printf("new zoom %f\n", fdf->zoom);
}

void	calc_offset(t_fdf *fdf)
{
	find_map_edges(fdf);
	fdf->offset_x = ((WIN_W - MENU_W) / 2) \
		- ((fdf->edge.real_w - 1) / 2) + MENU_W;
	fdf->offset_y = (WIN_H / 2) - ((fdf->edge.real_h - 1) / 2);
	if (fdf->edge.x_low < 0)
		fdf->offset_x += ft_abs(fdf->edge.x_low);
	if (fdf->edge.y_low < 0)
		fdf->offset_y += ft_abs(fdf->edge.y_low);
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
	int	i;
	int	j;

	calc_offset(fdf);
	// printf("z center: %d\n", (fdf->edge->z_high - fdf->edge->z_low) / 2);
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
			set_offset(&fdf->map[i][j], (fdf->offset_x + fdf->shift_x), \
				(fdf->offset_y + fdf->shift_y));
			// set_offset(&fdf->map[i][j], fdf->offset_x, fdf->offset_y);
	}
}
