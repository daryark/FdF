/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:34:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/18 16:17:09 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	swap_points(t_map *a, t_map *b)
{
	t_map	tmp;

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

void	make_zoom(t_map *point, float zoom)
{
	point->x *= zoom;
	point->y *= zoom;
	point->val *= zoom;
}

void	set_offset(t_map *point, int offset_x, int offset_y)
{
	point->x += offset_x;
	point->y += offset_y;
}

void	do_isometric(int *x, int *y, int *z, t_fdf *fdf)
{
	// float	a;

	// a = *x;
	// *x = (a - *y) * cos(0.53299);
	// *y = (a + *y) * sin(0.53299) - z;
	float angle_x = fdf->angle_x;
	float angle_y = fdf->angle_y;
	float angle_z = fdf->angle_z;
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
//{-1 1 0},  //{x},		{(-x + y + 0z)},	{-x+y}
//{ 0 1 0},	 //{y}, = 	{(0x + y + 0z)}, =	{y}
//{ 0 0 1}	 //{z}		{(0x + 0y + z)}		{z}