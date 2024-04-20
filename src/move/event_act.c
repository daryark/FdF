/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:43:50 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/20 22:13:52 by dyarkovs         ###   ########.fr       */
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
	printf("rotate z\n");
	if (keycode == HK_MINUS)
		fdf->angle_z -= 5;
	else
		fdf->angle_z += 5;
	angle_normailze(&fdf->angle_z);
}

void	do_shift(t_fdf *fdf)
{
	if (fdf->pressed.up)
		fdf->shift_y -= 20;
	if (fdf->pressed.down)
		fdf->shift_y += 20;
	if (fdf->pressed.left)
		fdf->shift_x -= 20;
	if (fdf->pressed.right)
		fdf->shift_x += 20;
}
