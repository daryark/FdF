/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:17:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/23 01:19:43 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fdf.h"

//just printing staff, remove after the whole function!!!
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
				ft_printf(" %d,%x " RE, fdf->map[i][j].val, fdf->map[i][j].color);
			}
			else
				ft_printf(" %d,%d ", fdf->map[i][j].x, fdf->map[i][j].y);
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}
static t_map	point(t_map p)
{
	return (p);
}

void	print_center_vector_helper(t_fdf *fdf)
{
	t_map ps;
	t_map px;
	t_map py;
	t_map pz;

ps = point((t_map){.x = (fdf->width / 2), .y = (fdf->height / 2), \
	.val = find_mid_z(fdf), .color = 0xff0000});
pz = point((t_map){.x = (fdf->width / 2), .y = (fdf->height / 2), \
	.val = find_mid_z(fdf)*4, .color = 0xff0000});
py = point((t_map){.x = (fdf->width / 2), .y = 0, \
	.val = find_mid_z(fdf), .color = 0xff0000});
px = point((t_map){.x = 0, .y = (fdf->height / 2), \
	.val = find_mid_z(fdf), .color = 0xff0000});
make_zoom(&ps, fdf->zoom);
make_zoom(&px, fdf->zoom);
make_zoom(&py, fdf->zoom);
make_zoom(&pz, fdf->zoom);
do_isometric(&ps.x, &ps.y, &ps.val, fdf);
do_isometric(&px.x, &px.y, &px.val, fdf);
do_isometric(&py.x, &py.y, &py.val, fdf);
do_isometric(&pz.x, &pz.y, &pz.val, fdf);
set_offset(&ps, (fdf->offset_x + fdf->shift_x), \
				(fdf->offset_y + fdf->shift_y));
set_offset(&px, (fdf->offset_x + fdf->shift_x), \
				(fdf->offset_y + fdf->shift_y));
set_offset(&py, (fdf->offset_x + fdf->shift_x), \
				(fdf->offset_y + fdf->shift_y));
set_offset(&pz, (fdf->offset_x + fdf->shift_x), \
				(fdf->offset_y + fdf->shift_y));
draw_line_algorithm(ps, px, fdf);
draw_line_algorithm(ps, py, fdf);
draw_line_algorithm(ps, pz, fdf);
draw_line_algorithm(ps, (t_map){.x = ps.x+10, .y = ps.y, .val = ps.val, .color = ps.color}, fdf);
draw_line_algorithm(ps, (t_map){.x = ps.x, .y = ps.y+10, .val = ps.val, .color = ps.color}, fdf);
draw_line_algorithm(ps, (t_map){.x = ps.x-10, .y = ps.y, .val = ps.val, .color = ps.color}, fdf);
draw_line_algorithm(ps, (t_map){.x = ps.x, .y = ps.y-10, .val = ps.val, .color = ps.color}, fdf);
}