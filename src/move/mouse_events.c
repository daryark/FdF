/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 04:03:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/25 04:48:02 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"


void	vector_show_event(t_fdf *fdf)
{
	fdf->pressed.vector = !fdf->pressed.vector;
	redraw_img(fdf);
}

void	orthographic_view_event(t_fdf *fdf)
{
	fdf->pressed.ortho = 1;
	fdf->pressed.iso = 0;
	redraw_img(fdf);
}

void	isometric_view_event(t_fdf *fdf)
{
	fdf->pressed.iso = 1;
	fdf->pressed.ortho = 0;
	redraw_img(fdf);
}
