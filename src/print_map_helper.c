/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:17:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/06 01:54:44 by dyarkovs         ###   ########.fr       */
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
}

void	print_center_vector_helper(t_fdf *fdf)
{
	int i;

	i = 0;
    while (i < WIN_HEIGHT)
    {    
        my_mlx_pixel_put(fdf->img, WIN_WIDTH/2, i, 0x8000ff00);
        my_mlx_pixel_put(fdf->img, (WIN_WIDTH/2)+ (MENU_WIDTH/2), i, 0x80ffff00);
        my_mlx_pixel_put(fdf->img, (WIN_WIDTH/2)+ MENU_WIDTH, i, 0x800000ff);
        i++;
    }
	i = 0;
	while (i < WIN_WIDTH)
        my_mlx_pixel_put(fdf->img, i++, WIN_HEIGHT/2, 0x80ffff00);
}