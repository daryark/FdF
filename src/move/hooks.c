/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:45:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/19 18:47:08 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	key_press_hook(int keycode, t_fdf *fdf)
{
	// ft_printf("key:	%d\n", keycode);
	if (keycode == CLOSE_BTN || keycode == HK_ESC)
		close_event(fdf);
	else if (keycode == HK_X)
		fdf->pre_event = HK_X;
	else if (keycode == HK_Z)
		fdf->pre_event = HK_Z;
	else if (keycode == HK_Y)
		fdf->pre_event = HK_Y;
	else if (keycode == HK_CTRL_L)
		fdf->pre_event = HK_CTRL_L;
	else if (keycode == HK_UP || keycode == HK_DOWN
		|| keycode == HK_LEFT || keycode == HK_RIGHT)
		move_event(fdf, keycode);
	else if ((keycode == HK_MINUS || keycode == HK_PLUS)
		&& !fdf->pre_event)
		zoom_event(fdf, keycode);
	else if ((keycode == HK_MINUS || keycode == HK_PLUS)
		&& fdf->pre_event == HK_CTRL_L)
		hight_change_event(fdf, keycode);
	else if ((keycode == HK_PLUS || keycode == HK_MINUS)
		&& (fdf->pre_event == HK_X || fdf->pre_event == HK_Z
		|| fdf->pre_event == HK_Y))
		rotate_event(fdf, keycode);
	return (0);
}

int	key_release_hook(int keycode, t_fdf *fdf)
{
	ft_printf("key:	%d\n", keycode);
	if (keycode == HK_Z && fdf->pre_event == HK_Z)
		fdf->pre_event = 0;
	else if (keycode == HK_X && fdf->pre_event == HK_X)
		fdf->pre_event = 0;
	else if (keycode == HK_Y && fdf->pre_event == HK_Y)
		fdf->pre_event = 0;
	else if (keycode == HK_CTRL_L && fdf->pre_event == HK_CTRL_L)
		fdf->pre_event = 0;
	else if ((keycode == HK_UP || keycode == HK_DOWN
			|| keycode == HK_LEFT || keycode == HK_RIGHT) \
			&& fdf->prev_mv && keycode == fdf->prev_mv)
		fdf->prev_mv = 0;
	return (0);
}
