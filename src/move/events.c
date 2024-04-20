/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:05:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/20 16:24:22 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	rotate_event(t_fdf *fdf, int keycode)
{
	if (fdf->pre_event == HK_X)
		rotate_x(fdf, keycode);
	else if (fdf->pre_event == HK_Z)
		rotate_z(fdf, keycode);
	else if (fdf->pre_event == HK_Y)
		rotate_y(fdf, keycode);
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
		fdf->zoom *= 0.75;
	else if (keycode == HK_PLUS)
		fdf->zoom *= 1.25;
	if (fdf->zoom < 1)
	{
		fdf->err = 1;
		fdf->zoom = 1;
	}
	else
		fdf->err = 0;
	redraw_img(fdf);
}

void	move_event(t_fdf *fdf, int keycode)
{
	if(is_relevant_shift(fdf, keycode))
		do_shift(fdf, keycode);
	if (fdf->prev_mv && is_relevant_shift(fdf, fdf->prev_mv))
		do_shift(fdf, fdf->prev_mv);
	else
		fdf->prev_mv = keycode;
	redraw_img(fdf);
}

void	close_event(t_fdf *fdf)
{
	// destroy_img(fdf);
	// mlx_destroy_window(fdf->mlx, fdf->window);
	clean_all(fdf); //*check leaks that way, when commented line
	exit(EXIT_SUCCESS);
}
