/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:43:50 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/21 04:19:32 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	angle_change(int *angle, int keycode)
{
	if (keycode == HK_MINUS)
		*angle -= 5;
	else
		*angle += 5;
	angle_normailze(angle);
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
