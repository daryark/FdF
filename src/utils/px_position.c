/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:15:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/14 23:52:27 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	adjust_zoom(t_fdf *fdf)
{
	float	potential_zoom_x;
	float	potential_zoom_y;

	map_real_size(fdf);
	potential_zoom_x = (float)(WIN_WIDTH - MENU_WIDTH) / \
		(float)fdf->corner->real_w;
	potential_zoom_y = (float)WIN_HEIGHT / (float)fdf->corner->real_h;
	if (potential_zoom_x < potential_zoom_y)
		fdf->zoom = potential_zoom_x;
	else
		fdf->zoom = potential_zoom_y;
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
	map_real_size(fdf);
	fdf->offset_x = ((WIN_WIDTH - MENU_WIDTH) / 2) \
		- ((fdf->corner->real_w - 1) / 2) + MENU_WIDTH;
	fdf->offset_y = (WIN_HEIGHT / 2) - ((fdf->corner->real_h - 1) / 2);
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
}

void	zoom_map_to_win_size(t_fdf *fdf)
{
	int	i;
	int	j;
	int	total_zoom;

	total_zoom = fdf->zoom;
	adjust_zoom(fdf);
	if (fdf->zoom < 0)
		return ;
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
			make_zoom(&fdf->map[i][j], fdf->zoom);
	}
	fdf->zoom *= total_zoom;
	printf("total zoom: %f\n", fdf->zoom);
}

void	center_map(t_fdf *fdf)
{
	int	i;
	int	j;

	calc_offset(fdf);
	check_corners_red(fdf); //just print helper, delete later
	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
			set_offset(&fdf->map[i][j], (fdf->offset_x + fdf->shift_x), (fdf->offset_y + fdf->shift_y));
	}
}
