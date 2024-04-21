/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:45:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/21 08:57:35 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	key_press_hook(int keycode, t_fdf *fdf)
{
	if (keycode == CLOSE_BTN || keycode == HK_ESC)
		close_event(fdf);
	if (keycode == HK_R)
		reset_event(fdf);
	if (keycode == HK_X)
		fdf->pressed.x = 1;
	else if (keycode == HK_Y)
		fdf->pressed.y = 1;
	else if (keycode == HK_Z)
		fdf->pressed.z = 1;
	else if (keycode == HK_CTRL_L)
		fdf->pressed.ctrl_l = 1;
	if (is_plus_minus_key(keycode) && is_xyz_key(fdf->pressed)
		&& !fdf->pressed.ctrl_l)
		rotate_event(fdf, keycode);
	if (is_plus_minus_key(keycode) && fdf->pressed.ctrl_l
		&& !is_xyz_key(fdf->pressed))
		hight_change_event(fdf, keycode);
	if (is_plus_minus_key(keycode) && !is_xyz_key(fdf->pressed)
		&& !fdf->pressed.ctrl_l)
		zoom_event(fdf, keycode);
	else if (is_move_key(keycode))
		move_event(fdf, keycode);
	return (0);
}

int	key_release_hook(int keycode, t_fdf *fdf)
{
	if (keycode == HK_Z && fdf->pressed.z)
		fdf->pressed.z = 0;
	else if (keycode == HK_X && fdf->pressed.x)
		fdf->pressed.x = 0;
	else if (keycode == HK_Y && fdf->pressed.y)
		fdf->pressed.y = 0;
	else if (keycode == HK_CTRL_L && fdf->pressed.ctrl_l)
		fdf->pressed.ctrl_l = 0;
	else if (is_move_key(keycode))
		move_key_release(fdf, keycode);
	return (0);
}

int	mouse_click_hook(int keycode, int x, int y, t_fdf *fdf)
{
	(void)fdf;
	if (keycode == HK_MOUSE_L)
	{
		if (x >= 100 && x <= 200 && y >= WIN_H - 200 && y <= WIN_H - 150) {
            reset_event(fdf);
            printf("Left-click event within the button area!\n");
        }
	}
	return (0);
}