/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:22:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/25 18:03:59 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	map_out_of_win(t_fdf *fdf)
{
	find_map_edges(fdf);
	if (fdf->edge.y_high <= 0 || fdf->edge.y_low >= WIN_H
		|| fdf->edge.x_high <= 0 || fdf->edge.x_low >= WIN_W)
		return (1);
	return (0);
}

int	is_relevant_shift(t_fdf *fdf)
{
	if (!(fdf->edge.y_high <= 0 && fdf->pressed.up)
		&& !(fdf->edge.y_low >= WIN_H && fdf->pressed.down)
		&& !(fdf->edge.x_high <= 0 && fdf->pressed.left)
		&& !(fdf->edge.x_low >= WIN_W && fdf->pressed.right))
		return (1);
	return (0);
}

int	is_move_key(int keycode)
{
	if (keycode == HK_RIGHT || keycode == HK_LEFT
		|| keycode == HK_DOWN || keycode == HK_UP)
		return (1);
	return (0);
}

int	is_plus_minus_key(int keycode)
{
	if (keycode == HK_MINUS || keycode == HK_PLUS)
		return (1);
	return (0);
}

void	angle_normailze(float *angle)
{
	while (!(*angle <= 360 && *angle >= 0))
	{
		if (*angle < 0)
			*angle += 360;
		else
			*angle -= 360;
	}
}
