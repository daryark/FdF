/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:43:50 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/20 16:22:47 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	rotate_x(t_fdf *fdf, int keycode)
{
	if (keycode == HK_MINUS)
		fdf->angle_x -= 5;
	else
		fdf->angle_x += 5;
	angle_normailze(&fdf->angle_x);
}

void	rotate_y(t_fdf *fdf, int keycode)
{
	if (keycode == HK_MINUS)
		fdf->angle_y -= 5;
	else
		fdf->angle_y += 5;
	angle_normailze(&fdf->angle_y);
}

void	rotate_z(t_fdf *fdf, int keycode)
{
	if (keycode == HK_MINUS)
		fdf->angle_z -= 5;
	else
		fdf->angle_z += 5;
	angle_normailze(&fdf->angle_z);
}

void	do_shift(t_fdf *fdf, int keycode)
{
	if (keycode == HK_UP)
		fdf->shift_y -= 30;
	else if (keycode == HK_DOWN)
		fdf->shift_y += 30;
	else if (keycode == HK_LEFT)
		fdf->shift_x -= 30;
	else if (keycode == HK_RIGHT)
		fdf->shift_x += 30;
}
