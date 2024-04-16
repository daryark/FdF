/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:45:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/16 03:39:48 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	high_change_event(t_fdf *fdf, int keycode)
{
	if (keycode == HK_PLUS)
		fdf->z_coef += 0.1;
	if (keycode == HK_MINUS)
		fdf->z_coef -= 0.1;
	redraw_img(fdf);
}

int	key_press_hook(int keycode, t_fdf *fdf)
{
	if (keycode == CLOSE_BTN || keycode == HK_ESC)
		close_event(fdf);
	else if (keycode == HK_UP || keycode == HK_DOWN
		|| keycode == HK_LEFT || keycode == HK_RIGHT)
		move_event(fdf, keycode);
	else if (keycode == HK_Z)
		fdf->z_event = 1;
	else if ((keycode == HK_MINUS || keycode == HK_PLUS)
		&& !fdf->z_event)
		zoom_event(fdf, keycode);
	else if ((keycode == HK_MINUS || keycode == HK_PLUS)
		&& fdf->z_event)
		high_change_event(fdf, keycode);
		// ft_printf("key:	%d\n", keycode);
	return (0);
}

int	key_release_hook(int keycode, t_fdf *fdf)
{
	if (keycode == HK_Z)
		fdf->z_event = 0;
	if ((keycode == HK_UP || keycode == HK_DOWN
			|| keycode == HK_LEFT || keycode == HK_RIGHT) \
			&& fdf->prev_mv && keycode == fdf->prev_mv)
		fdf->prev_mv = 0;
	return (0);
}
