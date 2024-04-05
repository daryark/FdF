/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:34:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/05 14:45:17 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	set_default_values(t_fdf *fdf)
{
	fdf->height = 0;
	fdf->width = 0;
	fdf->zoom = 1;
	fdf->slope = 0.0;
	fdf->map = NULL;
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->img = NULL;
	fdf->menu = NULL;
}

void    swap_points(t_map *p0, t_map *p1)
{
    t_map   tmp;

    tmp.color = p0->color;
    tmp.val = p0->val;
    tmp.x = p0->x;
    tmp.y = p0->y;
    p0->color = p1->color;
    p0->val = p1->val;
    p0->x = p1->x;
    p0->y = p1->y;
    p1->color = tmp.color;
    p1->val = tmp.val;
    p1->x = tmp.x;
    p1->y = tmp.y;
}
