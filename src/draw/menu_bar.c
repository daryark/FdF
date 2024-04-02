/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:28:02 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/03 00:13:57 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void    menu_bar_put(t_fdf *fdf)
{
    t_map   p0;

    fdf->menu_bar->img = mlx_new_image(fdf->mlx, 400, WIN_HEIGHT);
    fdf->menu_bar->addr = mlx_get_data_addr(fdf->menu_bar->img, &fdf->menu_bar->bits_per_pixel, &fdf->menu_bar->line_length, &fdf->menu_bar->endian);
    p0.x = 0;
	p0.y = 0;
	p0.color = 0x552f2f2f;
	p0.val = 0;
    ft_printf("menu.addr: %p, menu.img: %p\n", fdf->menu_bar->addr, fdf->menu_bar->img);
	fill_bg(400, WIN_HEIGHT, p0, fdf->menu_bar);
    }

void    fill_bg(int width, int height, t_map start, t_img *img)
{
    int     i;
    int     j;
    t_map   end;

    i = -1;
    end = start;
    end.x += width;
    while (++i < height)
    {
        j = -1;
        while (++j < width)
            draw_line_algorithm(start, end, img);
        start.y++;
        end.y++;
    }
}