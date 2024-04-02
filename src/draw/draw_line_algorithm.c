/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:52:24 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/02 23:58:10 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//return the array of dependent values for each independent value of the point
static int    *interpolate_values(int i0, int d0, int i1, int d1)
{
    int     *d_values;
    int     i;
    float   slope;
    float   d_cur;

    d_values = malloc(sizeof(int) * (i1 - i0));
    if (!d_values)
        return (NULL);
    slope = (float)(d1 - d0) / (i1 - i0);
    i = 0;
    d_cur = d0;
    while (i0++ < i1)
    {
        d_values[i] = d_cur;
        d_cur += slope;
        i++;
    }
    return (d_values);
}

//takes start and end points (p0, p1)
// point is of struct t_map that has x and y coordinates
void    draw_line_algorithm(t_map p0, t_map p1, t_img *img)
{
    int *d_values;
    int i;

    d_values = NULL;
    i = -1;
    if (p1.x - p0.x > p1.y - p0.y)
    {
        if (p0.x > p1.x)
            ft_swap(&p0.x, &p1.x);
        d_values = interpolate_values(p0.x, p0.y, p1.x, p1.y);
        if (!d_values)
            return ;
        while (p0.x < p1.x)
            my_mlx_pixel_put(img, p0.x++, d_values[++i], p0.color); //*what to do with color gradient
    }
    else
    {
        if (p0.y > p1.y)
            ft_swap(&p0.y, &p1.y);
        d_values = interpolate_values(p0.y, p0.x, p1.y, p1.x);
        if (!d_values)
            return ;
        while ( p0.y < p1.y)
            my_mlx_pixel_put(img, d_values[++i], p0.y++, p0.color);
    }
    if (d_values)
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

// void overlay_images(t_img *lower_img, t_img *upper_img, void *mlx_ptr, void *win_ptr) {
//     int x, y;
//     unsigned char alpha_upper, alpha_lower;
//     unsigned int blended_color;

//     for (y = 0; y < lower_img->height; y++) {
//         for (x = 0; x < lower_img->width; x++) {
//             // Get the alpha value of the upper image pixel
//             alpha_upper = (upper_img->addr[y * upper_img->line_length + x * 4 + 3]);
//             // Get the alpha value of the lower image pixel
//             alpha_lower = (lower_img->addr[y * lower_img->line_length + x * 4 + 3]);
//             // Calculate the blended color using alpha blending
//             blended_color = (alpha_upper * (upper_img->addr[y * upper_img->line_length + x * 4]) +
//                              alpha_lower * (lower_img->addr[y * lower_img->line_length + x * 4])) / (alpha_upper + alpha_lower);
//             // Update the lower image pixel with the blended color
//             *(unsigned int *)(lower_img->addr + y * lower_img->line_length + x * 4) = blended_color;
//         }
//     }
//     // Draw the resulting image onto the window
//     mlx_put_image_to_window(mlx_ptr, win_ptr, lower_img->img, 0, 0);
// }
