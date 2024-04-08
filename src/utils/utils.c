/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:34:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/09 00:37:07 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	set_default_values(t_fdf *fdf)
{
	fdf->height = 0;
	fdf->width = 0;
	fdf->zoom = 30;
    fdf->offset_x = 0;
    fdf->offset_y = 0;
	fdf->slope = 0.0;
	fdf->map = NULL;
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->img = NULL;
	fdf->menu = NULL;
}

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
