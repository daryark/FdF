/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:28:02 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/03 00:13:57 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	menu_choose(t_fdf *fdf)
{
	void	*menu;
	int		img_w;
	int		img_h;

	if (fdf->pressed.iso)
	{
		if (fdf->pressed.vector)
			menu = mlx_xpm_file_to_image(fdf->mlx, \
			"./extras/iso_von.xpm", &img_w, &img_h);
		else
			menu = mlx_xpm_file_to_image(fdf->mlx, \
			"./extras/iso_voff.xpm", &img_w, &img_h);
	}
	else
	{
		if (fdf->pressed.vector)
			menu = mlx_xpm_file_to_image(fdf->mlx, \
			"./extras/ort_von.xpm", &img_w, &img_h);
		else
			menu = mlx_xpm_file_to_image(fdf->mlx, \
			"./extras/ort_voff.xpm", &img_w, &img_h);
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, menu, 0, 0);
}

void	menu_put(t_fdf *fdf)
{
	fdf->menu->img = mlx_new_image(fdf->mlx, MENU_W, WIN_H);
	fdf->menu->addr = mlx_get_data_addr(fdf->menu->img, &fdf->menu->bpp, \
	&fdf->menu->len, &fdf->menu->endian);
	fill_bg(MENU_W, WIN_H, (t_map){.x = 0, .y = 0, .val = 0, \
		.color = 0x13191919}, fdf->menu);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->menu->img, 0, 0);
	menu_choose(fdf);
	warning_put(fdf);
}

void	fill_bg(int width, int height, t_map start, t_img *img)
{
	int	x;

	x = start.x;
	while (start.y < height)
	{
		while (start.x < width)
			my_mlx_pixel_put(img, start.x++, start.y, start.color);
		start.x = x;
		start.y++;
	}
}
