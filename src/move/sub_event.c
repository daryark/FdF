/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:20:14 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/23 13:58:52 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	is_xyz_key(t_pressed pr)
{
	if (pr.x || pr.z || pr.y)
		return (1);
	return (0);
}

void	move_key_release(t_fdf *fdf, int keycode)
{
	if (keycode == HK_RIGHT)
		fdf->pressed.right = 0;
	else if (keycode == HK_LEFT)
		fdf->pressed.left = 0;
	else if (keycode == HK_UP)
		fdf->pressed.up = 0;
	else if (keycode == HK_DOWN)
		fdf->pressed.down = 0;
}

void	reset_event(t_fdf *fdf)
{
	reset_screen_values(fdf);
	destroy_img(fdf);
	reset_map(fdf);
	transform_map(fdf);
	zoom_map_to_win_size(fdf);
	center_map(fdf);
	img_put(fdf);
}
