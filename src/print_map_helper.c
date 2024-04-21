/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:17:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/21 04:11:17 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../fdf.h"

//just printing staff, remove after the whole function!!!
// void	print_map(t_fdf *fdf, int modificator)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (fdf->height > ++i)
// 	{
// 		j = -1;
// 		while (fdf->width > ++j)
// 		{
// 			if (!modificator)
// 			{
// 				if (fdf->map[i][j].color == (unsigned int)(-1))
// 					ft_printf(RED);
// 				ft_printf(" %d,%x " RE, fdf->map[i][j].val, fdf->map[i][j].color);
// 			}
// 			else
// 				ft_printf(" %d,%d ", fdf->map[i][j].x, fdf->map[i][j].y);
// 		}
// 		ft_printf("\n");
// 	}
// 	ft_printf("\n");
// }

// void	print_center_vector_helper(t_fdf *fdf)
// {
// 	t_map p0;
// 	t_map p1;

// 		p0.x = (fdf->edge.x_high - fdf->edge.x_low)/2;
// 		p0.y = (fdf->edge.y_high - fdf->edge.y_low)/2;
// 		p0.val = 0;
// 		p0.color = 0x00ff00;
// 		// p1.x = (fdf->edge.x_high - fdf->edge.x_low)/2;
// 		// p1.y = (fdf->edge.y_high - fdf->edge.y_low)/2;
// 		// p1.val = 100;
// 		p1.x = 0;
// 		p1.y = 0;
// 		p1.val = 0;
// 		p1.color = 0xff0000;
// 		// printf("p0: %d,%d,%d\np1: %d,%d,%d\n", p0.x, p0.y, p0.val, p1.x, p1.y, p1.val);
// 		do_isometric(&p0.x, &p0.y, &p0.val, fdf);
// 		printf("My X: %f\n", p0.x);
//     	printf("My Y: %f\n", p0.y);
//     	printf("My Z: %f\n", p0.val);
// 		// do_isometric(&p1.x, &p1.y, &p1.val, fdf);
// 		// printf("p0: %d,%d,%d\np1: %d,%d,%d\n", p0.x, p0.y, p0.val, p1.x, p1.y, p1.val);
// 		set_offset(&p0, fdf->offset_x + fdf->shift_x, fdf->offset_y + fdf->shift_y);
// 		// set_offset(&p1, fdf->offset_x + fdf->shift_x, fdf->offset_y + fdf->shift_y);
// 		draw_line_algorithm(p0, p1, fdf);
// }

// void	check_edges_green(t_fdf *fdf)
// {
// 	int	i;
// 	int j;

// 	i = -1;
// 	while (++i < fdf->height)
// 	{
// 		j = -1;
// 		while (++j < fdf->width)
// 		{
// 			if (fdf->map[i][j].x == fdf->edge.x_low || fdf->map[i][j].y == fdf->edge.y_low
// 			|| fdf->map[i][j].x == fdf->edge.x_high || fdf->map[i][j].y == fdf->edge.y_high)
// 				fdf->map[i][j].color = 0x00ff00;
// 		}
// 	}
// }