/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:14:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/21 04:12:55 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void do_iso_one_axis(float *x, float *y, float *z, float mat[3][3])
{
    float   tmpx;
    float   tmpy;
    float   tmpz;

    tmpx = *x;
    tmpy = *y;
    tmpz = *z;
    *x = tmpx * mat[0][0] + tmpy * mat[0][1] + tmpz * mat[0][2];
    *y = tmpx * mat[1][0] + tmpy * mat[1][1] + tmpz * mat[1][2];
    *z = tmpx * mat[2][0] + tmpy * mat[2][1] + tmpz * mat[2][2];
}

void	do_isometric(int *x, int *y, int *z, t_fdf *fdf)
{
	float a_x;
	float a_y;
	float a_z;
    float x1;
    float y1;
    float z1;

    a_x = radian_angle(fdf->angle_x);
    a_y = radian_angle(fdf->angle_y);
    a_z = radian_angle(fdf->angle_z);
    x1 = (float)*x;
	y1 = (float)*y;
	z1 = (float)*z;
    do_iso_one_axis(&x1, &y1, &z1, (float[3][3]){{1, 0, 0}, {0, cos(a_x), -sin(a_x)}, {0, sin(a_x), cos(a_x)}});
    do_iso_one_axis(&x1, &y1, &z1, (float[3][3]){{cos(a_y), 0, sin(a_y)}, {0, 1, 0}, {-sin(a_y), 0, cos(a_y)}});
    do_iso_one_axis(&x1, &y1, &z1, (float[3][3]){{cos(a_z), -sin(a_z), 0}, {sin(a_z), cos(a_z), 0}, {0, 0, 1}});
	*x = (int)x1;
	*y = (int)y1;
	*z = (int)z1;
}
