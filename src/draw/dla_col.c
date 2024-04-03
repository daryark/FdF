/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:52:24 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/03 22:15:47 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//return dependent values for each independent value of the point
static int  interpolate_val(int i0, int i_curr, float slope)
{
    return (slope * (i_curr - i0));
}

static void    calc_slope(int i0, int d0, int i1, int d1, float *slope)
{
    *slope = (float)(d1 - d0) / (i1 - i0);
}

static unsigned int    interpolate_color(int i0, int i_curr, int i1, int clr0, int clr1)
{
    int cur_clr_slope;
    int r;
    int g;
    int b;

    cur_clr_slope = (i_curr - i0) / (i1 - i0);
    r = (int)(((clr1 >> 16 & 0xff) - (clr0 >> 16 & 0xff)) * cur_clr_slope);
    g = (int)(((clr1 >> 8 & 0xff) - (clr0 >> 8 & 0xff))* cur_clr_slope);
    b = (int)(((clr1 & 0xff) - (clr0 & 0xff))* cur_clr_slope);
    return ((unsigned int)(r << 16 | g << 8 | b));
}

//takes start and end points (p0, p1)
// point is of struct t_map that has x and y coordinates
void    draw_line_algorithm(t_map p0, t_map p1, t_fdf *fdf)
{
    int             dep_coord;
    unsigned int    cur_clr;
    int             i;

    if (p1.x - p0.x > p1.y - p0.y)
    {
        if (p0.x > p1.x)
            swap_points(&p0, &p1);
        calc_slope(p0.x, p0.y, p1.x, p1.y, &fdf->slope);
        i = p0.x - 1;
        while (++i < p1.x)
        {
            dep_coord = interpolate_val(p0.x, p0.x + i, fdf->slope);
            cur_clr = interpolate_color(p0.x, p0.x + i, p1.x, p0.color, p1.color);
            my_mlx_pixel_put(fdf->img, p0.x + i, dep_coord, cur_clr);
        }
    }
    else
    {
        if (p0.y > p1.y) 
            swap_points(&p0, &p1);
        calc_slope(p0.y, p0.y, p1.y, p1.y, &fdf->slope);
        i = p0.y - 1;
        while (++i < p1.y)
        {
            dep_coord = interpolate_val(p0.y, p0.y + i, fdf->slope);
            cur_clr = interpolate_color(p0.y, p0.y + i, p1.y, p0.color, p1.color);
            my_mlx_pixel_put(fdf->img, p0.y + i, dep_coord, cur_clr);
        }
    }
    ft_printf(YELLOW "slope: %d\n" RE, fdf->slope);
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
