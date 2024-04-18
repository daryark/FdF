/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:43:50 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/18 16:48:28 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"


static void	do_shift(t_fdf *fdf, int keycode)
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

void	move_img(t_fdf *fdf, int keycode)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			if (keycode == HK_UP)
				fdf->map[i][j].y -= 30;
			else if (keycode == HK_DOWN)
				fdf->map[i][j].y += 30;
			else if (keycode == HK_LEFT)
				fdf->map[i][j].x -= 30;
			else if (keycode == HK_RIGHT)
				fdf->map[i][j].x += 30;
		}
	}
	do_shift(fdf, keycode);
}