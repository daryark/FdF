/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:05:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/16 01:36:59 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

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

static void	do_shift(t_fdf *fdf, int keycode)
{
	if (keycode == HK_UP)
		fdf->shift_y -= 30;
	if (keycode == HK_DOWN)
		fdf->shift_y += 30;
	if (keycode == HK_LEFT)
		fdf->shift_x -= 30;
	if (keycode == HK_RIGHT)
		fdf->shift_x += 30;
}

void	move_event(t_fdf *fdf, int keycode)
{
	int	i;
	int	j;

	i = -1;
	destroy_img(fdf);
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			if (keycode == HK_UP)
				fdf->map[i][j].y -= 30;
			if (keycode == HK_DOWN)
				fdf->map[i][j].y += 30;
			if (keycode == HK_LEFT)
				fdf->map[i][j].x -= 30;
			if (keycode == HK_RIGHT)
				fdf->map[i][j].x += 30;
		}
	}
	do_shift(fdf, keycode);
	img_put(fdf);
}

void	close_event(t_fdf *fdf)
{
	// destroy_img(fdf);
	// mlx_destroy_window(fdf->mlx, fdf->window);
	clean_all(fdf); //*check leaks that way, when commented line
	exit(EXIT_SUCCESS);
}
