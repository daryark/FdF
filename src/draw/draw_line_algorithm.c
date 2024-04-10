/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:52:24 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/10 13:57:00 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//return the dependent value for each independent value of the point
static int  interpolate_val(int i0, int i_curr, int d0, float slope)
{
    return (int)(d0 + (slope * (i_curr - i0)));
}

static void    calc_slope(int i0, int d0, int i1, int d1, float *slope)
{
    *slope = (float)(d1 - d0) / (float)(i1 - i0);
}

#include <stdio.h>
unsigned int    interpolate_color(int i0, int i_curr, int i1, int clr0, int clr1)
{
    float cur_clr_slope;
    int r;
    int g;
    int b;

    cur_clr_slope = 0;
    if (i0 != i1 && clr0 != clr1)
        cur_clr_slope = (float)(i_curr - i0) / (float)(i1 - i0);
    r = (int)((clr0 >> 16 & 0xff) + ((clr1 >> 16 & 0xff) - (clr0 >> 16 & 0xff)) * cur_clr_slope);
    g = (int)((clr0 >> 8 & 0xff) + ((clr1 >> 8 & 0xff) - (clr0 >> 8 & 0xff))* cur_clr_slope);
    b = (int)((clr0 & 0xff) + ((clr1 & 0xff) - (clr0 & 0xff))* cur_clr_slope);
    return ((unsigned int)(r << 16 | g << 8 | b));
}

//takes start and end points (a, b)
// point is of struct t_map that has x and y coordinates
void    draw_line_algorithm(t_map a, t_map b, t_fdf *fdf)
{
    int             d_value;
    unsigned int    cur_clr;
    int             i;

    if (ft_abs(b.x - a.x) > ft_abs(b.y - a.y))
    {
        if (a.x > b.x)
            swap_points(&a, &b);
        calc_slope(a.x, a.y, b.x, b.y, &fdf->slope);
        i = a.x;
        while (i < b.x) 
        {
            d_value = interpolate_val(a.x, i, a.y, fdf->slope);
            cur_clr = interpolate_color(a.x, i, b.x, a.color, b.color);
            if (i > 0 && i <= WIN_WIDTH)
                my_mlx_pixel_put(fdf->img, i, d_value, cur_clr);
            i++;
        }
    }
    else
    {
        if (a.y > b.y)
            swap_points(&a, &b);
        calc_slope(a.y, a.x, b.y, b.x, &fdf->slope);
        i = a.y;
        while (i < b.y)
        {
            d_value = interpolate_val(a.y, i, a.x, fdf->slope);
            cur_clr = interpolate_color(a.y, i, b.y, a.color, b.color);
            if (i > 0 && i <= WIN_HEIGHT)
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