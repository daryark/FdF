/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:52:24 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/01 22:15:45 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//return the array of dependent values for each independent value of the point
static int    *interpolate_values(int i0, int d0, int i1, int d1)
{
    int *d_values;
    int i;
    int slope;

    d_values = malloc(sizeof(int) * (i1 - i0));
    slope = (d1 - d0)/(i1 - i0);
    i = 0;
    while (i0 <= i1)
    {
        d_values[i] = d0;
        d0 += slope;
        i++;
        i0++;
    }
    return (d_values);
}

//takes start and end points (p0, p1)
// point is of struct t_map that has x and y coordinates
void    draw_line_algorithm(t_map p0, t_map p1, t_img *img)
{
    int *d_values;

    if (p1.x - p0.x > p1.y - p0.y)
    {
        if (p0.x > p1.x)
            ft_swap(&p0.x, &p1.x);
        d_values = interpolate_values(p0.x, p0.y, p1.x, p1.y);
        while (p0.x++ < p1.x)
            my_mlx_pixel_put(img, p0.x, *d_values++, p0.color); //*what to do with color gradient
    }
    else
    {
        if (p1.y - p0.y > p1.x - p0.x)
            ft_swap(&p0.y, &p1.y);
        d_values = interpolate_values(p0.y, p0.x, p1.y, p1.x);
        while ( p0.y++ < p1.y)
            my_mlx_pixel_put(img, *d_values++, p0.y, p0.color);        
    }
    free(d_values);
}
//one coordinate is independent(i), other - dependent(d) on first coordinte
// the coordinate which has more dots on the axis is independent.
// if Y is independent, than calculate opposite.
// if the line goes from rigth to left (backwards on the screen), swap start/end points

void    img_put(t_fdf *fdf)
{
    int i;
    int j;

    i = -1;
    ft_printf("img_put\n");
    while (++i < fdf->height)
    {
        j = -1;
        while (++j < fdf->width)
        {
            if (j + 1 < fdf->width)
                 draw_line_algorithm(fdf->map[i][j], fdf->map[i][j + 1], fdf->img);
            if (i + 1 < fdf->height)
                 draw_line_algorithm(fdf->map[i][j], fdf->map[i + 1][j], fdf->img);
        }
    }
}