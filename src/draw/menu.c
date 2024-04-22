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

//*change the menu placement, when height > width
// with portrait direction, put menu on top for full width, 1/4 height
void	menu_put(t_fdf *fdf)
{
	// (void)fdf;
	t_map	p0;
	// void	*img;
	// char	*relative_path = "./menu6.xpm";
	// int		img_width;
	// int		img_height;

	p0.x = 0;
	p0.y = 0;
	p0.color = 0x552f2f2f;
	p0.val = 0;
	fdf->menu->img = mlx_new_image(fdf->mlx, MENU_W, WIN_H);
	fdf->menu->addr = mlx_get_data_addr(fdf->menu->img, &fdf->menu->bpp, \
	&fdf->menu->len, &fdf->menu->endian);
	fill_bg(MENU_W, WIN_H, p0, fdf->menu);
	// img = mlx_xpm_file_to_image(fdf->mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->menu->img, 0, 0);
	// mlx_put_image_to_window(fdf->mlx, fdf->window, img, 0, 0);
	warning_put(fdf);
}

void	fill_bg(int width, int height, t_map start, t_img *img)
{
	int	x;

	x = start.x;
	while (start.y < height)
	{
		while (start.x < width)
		{
			if (start.y == (WIN_H - 40))
				my_mlx_pixel_put(img, start.x++, start.y, 0xa1ffffff);
			else
				my_mlx_pixel_put(img, start.x++, start.y, start.color);
		}
		start.x = x;
		start.y++;
	}
}

//*if screen sizes less then the height of text put into it, adjust line gaps
// void	menu_text_put(t_fdf *fdf)
// {
// 	int	line_y;
// 	int	clr;

// 	line_y = 300;
// 	clr = 0xdcdcdc;
// 	mlx_string_put(fdf->mlx, fdf->window, 30, line_y, clr, "MENU BAR");
// 	mlx_string_put(fdf->mlx, fdf->window, 30, line_y += 50, clr, "< /\\ \\/ >");
// 	mlx_string_put(fdf->mlx, fdf->window, 30, line_y += 30, clr, "second rule");
// 	mlx_string_put(fdf->mlx, fdf->window, 30, line_y += 30, clr, "third rule");
// }
