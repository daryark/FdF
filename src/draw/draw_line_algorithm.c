/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:52:24 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/22 23:55:06 by dyarkovs         ###   ########.fr       */
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

static unsigned int	interpolate_color(int i_curr, t_map p0, t_map p1)
{
	float	cur_clr_slope;
	int		r;
	int		g;
	int		b;

	cur_clr_slope = 0.0;
	if (p0.x != p1.x && (int)p0.color != (int)p1.color)
		cur_clr_slope = (float)(i_curr - p0.x) / (float)(p1.x - p0.x);
	r = (int)(((int)p0.color >> 16 & 0xff) + \
		(((int)p1.color >> 16 & 0xff) - ((int)p0.color >> 16 & 0xff)) \
		* cur_clr_slope);
	g = (int)(((int)p0.color >> 8 & 0xff) + (((int)p1.color >> 8 & 0xff) \
		- ((int)p0.color >> 8 & 0xff)) * cur_clr_slope);
	b = (int)(((int)p0.color & 0xff) + (((int)p1.color & 0xff) - \
		((int)p0.color & 0xff)) * cur_clr_slope);
	return ((unsigned int)(r << 16 | g << 8 | b));
}

static void	draw_line_pixels(t_map a, t_map b, t_fdf *fdf, int swap)
{
	int				d_value;
	unsigned int	cur_clr;
	int				i;

	if (a.x > b.x)
		swap_points(&a, &b);
	fdf->slope = (float)(b.y - a.y) / (float)(b.x - a.x);
	i = a.x;
	while (i < b.x)
	{
		d_value = (int)(a.y + (fdf->slope * (i - a.x)));
		cur_clr = interpolate_color(i, a, b);
		if (((i >= 0 && i < WIN_W) && (d_value >= 0 && d_value < WIN_H))
			&& !swap)
			my_mlx_pixel_put(fdf->img, i, d_value, cur_clr);
		else if ((d_value >= 0 && d_value < WIN_W) && (i >= 0 && i < WIN_H)
			&& swap)
			my_mlx_pixel_put(fdf->img, d_value, i, cur_clr);
		i++;
	}
}

void	ft_fswap(float *a, float *b)
{
    float tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
//takes start and end points (a, b)
// point is of struct t_map that has x and y coordinates
void	draw_line_algorithm(t_map a, t_map b, t_fdf *fdf)
{
	if (ft_abs(b.x - a.x) < ft_abs(b.y - a.y))
	{
		ft_fswap(&a.x, &a.y);
		ft_fswap(&b.x, &b.y);
		draw_line_pixels(a, b, fdf, 1);
	}
	else
		draw_line_pixels(a, b, fdf, 0);
}
//one coordinate is independent(i), other - dependent(d) on first coordinte
// the coordinate which has more dots on the axis is independent.
// if Y is independent, than calculate opposite.
// if the line goes from rigth to left (backwards on the screen),
// swap start/end points
