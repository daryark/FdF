/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:43:50 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/25 19:20:56 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	angle_change(float *angle, int keycode, float rot_num)
{
	if (keycode == HK_MINUS)
		*angle -= rot_num;
	else
		*angle += rot_num;
	angle_normailze(angle);
}

void	do_shift(t_fdf *fdf)
{
	if (fdf->pressed.up)
		fdf->shift_y -= 30;
	if (fdf->pressed.down)
		fdf->shift_y += 30;
	if (fdf->pressed.left)
		fdf->shift_x -= 30;
	if (fdf->pressed.right)
		fdf->shift_x += 30;
}

void	make_zoom(t_map *point, float zoom)
{
	point->x *= zoom;
	point->y *= zoom;
	point->val *= zoom;
}

void	set_offset(t_map *point, t_fdf *fdf)
{
	point->x += (fdf->offset_x + fdf->shift_x);
	point->y += (fdf->offset_y + fdf->shift_y);
}
