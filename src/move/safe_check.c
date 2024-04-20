/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:22:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/20 17:10:15 by dyarkovs         ###   ########.fr       */
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
int	is_relevant_shift(t_fdf *fdf, int keycode)
{
	if (!(fdf->edge.y_high <= 0 && keycode == HK_UP)
		&& !(fdf->edge.y_low >= WIN_H && keycode == HK_DOWN)
		&& !(fdf->edge.x_high <= 0 && keycode == HK_LEFT)
		&& !(fdf->edge.x_low >= WIN_W && keycode == HK_RIGHT))
		return (1);
	return (0);
}
int	is_move_key(int keycode)
{
	if(keycode == HK_RIGHT || keycode == HK_LEFT
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

int is_xyz_key(int keycode)
{
	if (keycode == HK_X || keycode == HK_Z
		|| keycode == HK_Y)
		return (1);
	return (0);
}