/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:39:26 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/23 01:41:47 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"\

void    transform_point(t_map *p, t_fdf *fdf)
{
        p->val *= fdf->z_coef;
		make_zoom(p, fdf->zoom);
		do_isometric(p, fdf);
}