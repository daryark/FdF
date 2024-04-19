/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:14:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/19 22:14:42 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	do_isometric(int *x, int *y, int *z, t_fdf *fdf)
{
	// float	a;

	// a = *x;
	// *x = (a - *y) * cos(0.53299);
	// *y = (a + *y) * sin(0.53299) - z;
	float angle_x = (float)fdf->angle_x;
	float angle_y = (float)fdf->angle_y;
	float angle_z = (float)fdf->angle_z;
    // Convert angles from degrees to radians
    angle_x = angle_x * M_PI / 180.0;
    angle_y = angle_y * M_PI / 180.0;
    angle_z = angle_z * M_PI / 180.0;

    // Rotation around x-axis
    float rotation_x[3][3] = {
        {1, 0, 0},
        {0, cos(angle_x), -sin(angle_x)},
        {0, sin(angle_x), cos(angle_x)}
    };

    // Rotation around y-axis
    float rotation_y[3][3] = {
        {cos(angle_y), 0, sin(angle_y)},
        {0, 1, 0},
        {-sin(angle_y), 0, cos(angle_y)}
    };

    // Rotation around z-axis
    float rotation_z[3][3] = {
        {cos(angle_z), -sin(angle_z), 0},
        {sin(angle_z), cos(angle_z), 0},
        {0, 0, 1}
    };

    // Apply rotations
	float x1 = (float)*x;
	float y1 = (float)*y;
	float z1 = (float)*z;
    float tmp_x = x1;
    float tmp_y = y1;
    float tmp_z = z1;

    x1 = tmp_x * rotation_x[0][0] + tmp_y * rotation_x[0][1] + tmp_z * rotation_x[0][2];
    y1 = tmp_x * rotation_x[1][0] + tmp_y * rotation_x[1][1] + tmp_z * rotation_x[1][2];
    z1 = tmp_x * rotation_x[2][0] + tmp_y * rotation_x[2][1] + tmp_z * rotation_x[2][2];

    tmp_x = x1;
    tmp_y = y1;
    tmp_z = z1;

    x1 = tmp_x * rotation_y[0][0] + tmp_y * rotation_y[0][1] + tmp_z * rotation_y[0][2];
    y1 = tmp_x * rotation_y[1][0] + tmp_y * rotation_y[1][1] + tmp_z * rotation_y[1][2];
    z1 = tmp_x * rotation_y[2][0] + tmp_y * rotation_y[2][1] + tmp_z * rotation_y[2][2];

    tmp_x = x1;
    tmp_y = y1;
    tmp_z = z1;

    x1 = tmp_x * rotation_z[0][0] + tmp_y * rotation_z[0][1] + tmp_z * rotation_z[0][2];
    y1 = tmp_x * rotation_z[1][0] + tmp_y * rotation_z[1][1] + tmp_z * rotation_z[1][2];
    z1 = tmp_x * rotation_z[2][0] + tmp_y * rotation_z[2][1] + tmp_z * rotation_z[2][2];
	*x = (int)x1;
	*y = (int)y1;
	*z = (int)z1;
}
