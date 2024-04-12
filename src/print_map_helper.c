/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:17:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/12 17:09:41 by dyarkovs         ###   ########.fr       */
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
				ft_printf(GREEN " %d,%d " RE, fdf->map[i][j].x, fdf->map[i][j].y);
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	print_center_vector_helper(t_fdf *fdf)
{
	int i;

	i = -1;
    while (++i < WIN_HEIGHT)
    {    
        // my_mlx_pixel_put(fdf->img, WIN_WIDTH/2, i, 0x1a00ff00);
        // my_mlx_pixel_put(fdf->img, (WIN_WIDTH/2)+ MENU_WIDTH, i, 0x800000ff);
        my_mlx_pixel_put(fdf->img, (WIN_WIDTH / 2) + (MENU_WIDTH / 2), i, 0x0d950d);
    }
	i = MENU_WIDTH - 1;
	while (++i < WIN_WIDTH)
        my_mlx_pixel_put(fdf->img, i, WIN_HEIGHT/2, 0x0d950d);
}

void	check_corners_red(t_fdf *fdf)
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
				fdf->map[i][j].color = 0xff0000;
		}
	}
}