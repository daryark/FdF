/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:05:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/26 13:50:39 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	rotate_event(t_fdf *fdf, int keycode, float rot_num)
{
	if (fdf->pressed.x)
		angle_change(&fdf->angle_x, keycode, rot_num);
	if (fdf->pressed.y)
		angle_change(&fdf->angle_y, keycode, rot_num);
	if (fdf->pressed.z)
		angle_change(&fdf->angle_z, keycode, rot_num);
	redraw_img(fdf);
}

void	hight_change_event(t_fdf *fdf, int keycode)
{
	if (keycode == HK_PLUS)
		fdf->z_coef += 0.1;
	if (keycode == HK_MINUS)
		fdf->z_coef -= 0.1;
	redraw_img(fdf);
}

void	zoom_event(t_fdf *fdf, int keycode)
{
	if (keycode == HK_MINUS)
		fdf->zoom *= 0.9;
	else if (keycode == HK_PLUS)
		fdf->zoom *= 1.1;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
	else if (fdf->zoom > 1000)
		fdf->zoom = 1000;
	redraw_img(fdf);
}

void	move_event(t_fdf *fdf, int keycode)
{
	if (keycode == HK_UP)
		fdf->pressed.up = 1;
	else if (keycode == HK_DOWN)
		fdf->pressed.down = 1;
	else if (keycode == HK_LEFT)
		fdf->pressed.left = 1;
	else if (keycode == HK_RIGHT)
		fdf->pressed.right = 1;
	if (is_relevant_shift(fdf))
		do_shift(fdf);
	redraw_img(fdf);
}

void	close_event(t_fdf *fdf)
{
	fdf->pressed.r = 0;
	ft_putendl_fd(GREEN "Close the program" RE, 1);
	exit(EXIT_SUCCESS);
}
