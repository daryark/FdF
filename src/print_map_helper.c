/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:17:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/18 16:18:30 by dyarkovs         ###   ########.fr       */
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

void	print_center_vector_helper(t_fdf *fdf)
{
	int i;
	int	x;
	int	y;
	int	z;

	i = -1;
    while (++i < WIN_HEIGHT)
    {    
		x = (WIN_WIDTH / 2) + (MENU_WIDTH / 2);
		y = i;
		z = 0;
        // my_mlx_pixel_put(fdf->img, WIN_WIDTH/2, i, 0x1a00ff00);
        // my_mlx_pixel_put(fdf->img, (WIN_WIDTH/2)+ MENU_WIDTH, i, 0x800000ff);
		// set_offset(&(t_map){.x = x, .y = y, .val = z, .color = 0}, fdf->offset_x, fdf->offset_y);
		do_isometric(&x, &y, &z, fdf);
        // my_mlx_pixel_put(fdf->img, (WIN_WIDTH / 2) + (MENU_WIDTH / 2), i, 0x0d950d);
        my_mlx_pixel_put(fdf->img, x, y, 0x0d950d);
    }

	i = MENU_WIDTH - 1;
	while (++i < WIN_WIDTH)
    {   
		x = i;
		y = WIN_HEIGHT/2;
		z = 0;
		do_isometric(&x, &y, &z, fdf);
		// set_offset(&(t_map){.x = x, .y = y, .val = z, .color = 0}, fdf->offset_x, fdf->offset_y);
		my_mlx_pixel_put(fdf->img, x, y, 0x0d950d);
	}
	// i = fdf->corner->y_low;
	// while (i < fdf->corner->y_high)
	// {
	// 	x = 0;
	// 	y = 0;
	// 	z = i;
	// 	do_isometric(&x, &y, &z);
	// 	my_mlx_pixel_put(fdf->img, x, y, 0x0d950d);
	// }
        // my_mlx_pixel_put(fdf->img, i, WIN_HEIGHT/2, 0x0d950d);
}

void	check_corners_green(t_fdf *fdf)
{
	int	i;
	int j;

	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			if (fdf->map[i][j].x == fdf->corner->x_low || fdf->map[i][j].y == fdf->corner->y_low
			|| fdf->map[i][j].x == fdf->corner->x_high || fdf->map[i][j].y == fdf->corner->y_high)
				fdf->map[i][j].color = 0x00ff00;
		}
	}
}