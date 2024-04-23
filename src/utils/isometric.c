/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:14:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/23 13:57:12 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

float	radian_angle(float angle)
{
	return (angle * M_PI / 180.0);
}

static void	do_iso_one_axis(t_map *p, float mat[3][3])
{
	float	tmpx;
	float	tmpy;
	float	tmpz;

	tmpx = p->x;
	tmpy = p->y;
	tmpz = p->val;
	p->x = tmpx * mat[0][0] + tmpy * mat[0][1] + tmpz * mat[0][2];
	p->y = tmpx * mat[1][0] + tmpy * mat[1][1] + tmpz * mat[1][2];
	p->val = tmpx * mat[2][0] + tmpy * mat[2][1] + tmpz * mat[2][2];
}

void	do_isometric(t_map *p, t_fdf *fdf)
{
	float	a_x;
	float	a_y;
	float	a_z;

	a_x = radian_angle(fdf->angle_x);
	a_y = radian_angle(fdf->angle_y);
	a_z = radian_angle(fdf->angle_z);
	do_iso_one_axis(p, (float [3][3]) \
		{{1, 0, 0}, \
		{0, cos(a_x), -sin(a_x)}, \
		{0, sin(a_x), cos(a_x)}});
	do_iso_one_axis(p, (float [3][3]) \
		{{cos(a_y), 0, sin(a_y)}, \
		{0, 1, 0}, \
		{-sin(a_y), 0, cos(a_y)}});
	do_iso_one_axis(p, (float [3][3]) \
		{{cos(a_z), -sin(a_z), 0}, \
		{sin(a_z), cos(a_z), 0}, \
		{0, 0, 1}});
}
