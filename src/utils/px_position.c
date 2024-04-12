/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:15:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/12 22:43:24 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	calc_zoom(t_fdf *fdf)
{
	float	potential_zoom_x;
	float	potential_zoom_y;
	int		real_h;
	int		real_w;

	real_w = fdf->corner->x_high - fdf->corner->x_low;
	real_h = fdf->corner->y_high - fdf->corner->y_low;
	potential_zoom_x = (float)(WIN_WIDTH - MENU_WIDTH) / (float)real_w;
	potential_zoom_y = (float)WIN_HEIGHT / (float)real_h;
	if (potential_zoom_x < potential_zoom_y)
		fdf->zoom = potential_zoom_x;
	else
		fdf->zoom = potential_zoom_y;
	printf("new zoom %f\n", fdf->zoom);
}

void	calc_offset(t_fdf *fdf)
{
	int	real_w;
	int	real_h;

	real_w = (fdf->corner->x_high - fdf->corner->x_low);
	real_h = (fdf->corner->y_high - fdf->corner->y_low);
	fdf->offset_x = ((WIN_WIDTH - MENU_WIDTH) / 2) \
		- ((real_w - 1) / 2) + MENU_WIDTH;
	fdf->offset_y = (WIN_HEIGHT / 2) - ((real_h - 1) / 2);
	if (fdf->corner->x_low < 0)
		fdf->offset_x += ft_abs(fdf->corner->x_low);
	if (fdf->corner->y_low < 0)
		fdf->offset_y += ft_abs(fdf->corner->y_low);
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
			make_zoom(&fdf->map[i][j], fdf->zoom);
			do_isometric(&fdf->map[i][j].x, &fdf->map[i][j].y, \
				fdf->map[i][j].val);
		}
	}
	map_real_size(fdf);
	calc_zoom(fdf);
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
			make_zoom(&fdf->map[i][j], fdf->zoom);
	}
}

void	center_map(t_fdf *fdf)
{
	int	i;
	int	j;

	map_real_size(fdf);
	calc_offset(fdf);
	check_corners_red(fdf); //just print helper, delete later
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
			set_offset(&fdf->map[i][j], fdf->offset_x, fdf->offset_y);
	}
}
