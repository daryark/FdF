/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:52:24 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/06 00:59:27 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//return the dependent value for each independent value of the point
static int  interpolate_val(int i0, int i_curr, int d0, float slope)
{
    return (d0 + (slope * (i_curr - i0)));
}

static void    calc_slope(int i0, int d0, int i1, int d1, float *slope)
{
    *slope = (float)(d1 - d0) / (i1 - i0);
}

#include <stdio.h>
// static unsigned int    interpolate_color(int i0, int i_curr, int i1, int clr0, int clr1)
// {
//     float cur_clr_slope;
//     int r;
//     int g;
//     int b;

//     // cur_clr_slope = (i_curr - i0) / (i1 - i0);
//     cur_clr_slope = (1 / (i1 - i0)) * (i_curr - i0);
//     printf(GREEN "%f " RE, cur_clr_slope);
//     r = (int)(((clr1 >> 16 & 0xff) - (clr0 >> 16 & 0xff)) * cur_clr_slope);
//     g = (int)(((clr1 >> 8 & 0xff) - (clr0 >> 8 & 0xff))* cur_clr_slope);
//     b = (int)(((clr1 & 0xff) - (clr0 & 0xff))* cur_clr_slope);
//     return ((unsigned int)(r << 16 | g << 8 | b));
// }

//takes start and end points (p0, p1)
// point is of struct t_map that has x and y coordinates
void    draw_line_algorithm(t_map p0, t_map p1, t_fdf *fdf)
{
    int             d_value;
    unsigned int    cur_clr;
    int             i;

    cur_clr = 0xffffff;
    if (p0.color != 0xffffff)
        cur_clr = p0.color;
    else if (p1.color != 0xffffff)
        cur_clr = p1.color;
    if (p1.x - p0.x > p1.y - p0.y)
    {
        if (p0.x > p1.x)
            swap_points(&p0, &p1);
        calc_slope(p0.x, p0.y, p1.x, p1.y, &fdf->slope);
        i = p0.x;
        while (i < p1.x) 
        {
            d_value = interpolate_val(p0.x, i, p0.y, fdf->slope);
            // cur_clr = interpolate_color(p0.x, i, p0.x, p0.color, p1.color);
            // printf(YELLOW "%u " RE, cur_clr);
            my_mlx_pixel_put(fdf->img, i, d_value, cur_clr);
            i++;
        }
    }
    else
    {
        if (p0.y > p1.y)
            swap_points(&p0, &p1);
        calc_slope(p0.y, p0.x, p1.y, p1.x, &fdf->slope);
        i = p0.y;
        while (i < p1.y)
        {
            d_value = interpolate_val(p0.y, i, p0.x, fdf->slope);
            // cur_clr = interpolate_color(p0.y, i, p0.y, p0.color, p1.color);
            // printf(RED "%u " RE, cur_clr);

            my_mlx_pixel_put(fdf->img, d_value, i, cur_clr);
            i++;
        }
    }
}
//one coordinate is independent(i), other - dependent(d) on first coordinte
// the coordinate which has more dots on the axis is independent.
// if Y is independent, than calculate opposite.
// if the line goes from rigth to left (backwards on the screen), swap start/end points



//***
// t_color	interpolate_color(t_color start, t_color end, float t)
// {
//     t_color result;
//     result.red = start.red + (int)((end.red - start.red) * t);
//     result.green = start.green + (int)((end.green - start.green) * t);
//     result.blue = start.blue + (int)((end.blue - start.blue) * t);
//     return result;
// }

// void draw_gradient_line(int x0, int y0, int x1, int y1, t_color start_color, t_color end_color, t_data *img)
// {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int steps = dx > dy ? dx : dy;

//     float x_increment = (float)(x1 - x0) / steps;
//     float y_increment = (float)(y1 - y0) / steps;
//     float color_increment = 1.0 / steps;

//     float x = x0;
//     float y = y0;
//     float t = 0.0;

//     for (int i = 0; i <= steps; i++) {
//         t_color color = interpolate_color(start_color, end_color, t);
//         int color_hex = (color.red << 16) | (color.green << 8) | color.blue;
//         my_mlx_pixel_put(img, (int)x, (int)y, color_hex);
//         x += x_increment;
//         y += y_increment;
//         t += color_increment;
//     }
// }