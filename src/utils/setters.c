/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:34:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/11 03:05:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void    swap_points(t_map *a, t_map *b)
{
    t_map   tmp;

    tmp.color = a->color;
    tmp.val = a->val;
    tmp.x = a->x;
    tmp.y = a->y;
    a->color = b->color;
    a->val = b->val;
    a->x = b->x;
    a->y = b->y;
    b->color = tmp.color;
    b->val = tmp.val;
    b->x = tmp.x;
    b->y = tmp.y;
}

void	make_zoom(t_map *point, int zoom)
{
	point->x *= zoom;
	point->y *= zoom;
	point->val = point->val * (1 + (zoom - 1) * point->val / WIN_HEIGHT);
    // point->val = point->val * 20;
}

void	set_offset(t_map *point, int offset_x, int offset_y)
{
	point->x += offset_x;
	point->y += offset_y;
}

void    do_isometric(int *x, int *y, int z)
{
	float a;
	
	a = *x;
    *x = (a - *y) * cos(0.53299);
    *y = (a + *y) * sin(0.53299) - z;
}
