/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:17:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/28 21:21:07 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//just printing function
void	print_map(t_fdf *fdf, int modificator)
{
	int	i;
	int	j;

	i = -1;
	while (fdf->height > ++i)
	{
		j = -1;
		while (fdf->width > ++j)
		{
			if (!modificator)
			{
				if (fdf->map[i][j].color == (unsigned int)(-1))
					ft_printf(RED);
				ft_printf(" %d,%x " RE, fdf->map[i][j].val, \
				fdf->map[i][j].color);
			}
			else
				ft_printf(" %d,%d ", fdf->map[i][j].x, fdf->map[i][j].y);
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

static void	print_one_axis_helper(t_map s, t_map e, t_fdf *fdf)
{
	transform_point(&s, fdf);
	transform_point(&e, fdf);
	set_offset(&s, fdf);
	set_offset(&e, fdf);
	draw_line_algorithm(s, e, fdf);
}

static void	draw_x_helper(t_map ps, t_fdf *fdf)
{
	transform_point(&ps, fdf);
	set_offset(&ps, fdf);
	draw_line_algorithm(ps, (t_map){.x = ps.x + 10, .y = ps.y, \
	.val = ps.val, .color = ps.color}, fdf);
	draw_line_algorithm(ps, (t_map){.x = ps.x, .y = ps.y + 10, \
	.val = ps.val, .color = ps.color}, fdf);
	draw_line_algorithm(ps, (t_map){.x = ps.x - 10, .y = ps.y, \
	.val = ps.val, .color = ps.color}, fdf);
	draw_line_algorithm(ps, (t_map){.x = ps.x, .y = ps.y - 10, \
	.val = ps.val, .color = ps.color}, fdf);
}

void	print_center_vector_helper(t_fdf *fdf)
{
	t_map	ps;
	t_map	px;
	t_map	py;
	t_map	pz;

	ps = (t_map){.x = (fdf->width / 2), \
	.y = (fdf->height / 2), .val = fdf->zheight / 2, .color = 0xff0000};
	px = (t_map){.x = 0, \
	.y = (fdf->height / 2), .val = fdf->zheight / 2, .color = 0x00ff00};
	py = (t_map){.x = (fdf->width / 2), \
	.y = 0, .val = fdf->zheight / 2, .color = 0x0000ff};
	pz = (t_map){.x = (fdf->width / 2), \
	.y = (fdf->height / 2), .val = fdf->zheight, .color = 0xff00ff};
	print_one_axis_helper(ps, px, fdf);
	print_one_axis_helper(ps, py, fdf);
	print_one_axis_helper(ps, pz, fdf);
	draw_x_helper(ps, fdf);
}
