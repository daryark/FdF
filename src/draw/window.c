/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 03:40:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/24 21:14:04 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// go to first window px and move it to px: pass rows before
// needed line +  pxs' inside line. fill the px with color;
void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	redraw_img(t_fdf *fdf)
{
	destroy_img(fdf);
	reset_map(fdf);
	transform_map(fdf);
	center_map(fdf);
	img_put(fdf);
}

static void	draw_map(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			if (j + 1 < fdf->width
				&& fdf->map[i][j].color != (unsigned int)(-1)
				&& fdf->map[i][j + 1].color != (unsigned int)(-1))
				draw_line_algorithm(fdf->map[i][j], \
					fdf->map[i][j + 1], fdf);
			if (i + 1 < fdf->height
				&& fdf->map[i][j].color != (unsigned int)(-1)
				&& fdf->map[i + 1][j].color != (unsigned int)(-1))
				draw_line_algorithm(fdf->map[i][j], fdf->map[i + 1][j], fdf);
		}
	}
}

void	img_put(t_fdf *fdf)
{
	fdf->img = malloc(sizeof(t_img));
	fdf->menu = malloc(sizeof(t_img));
	if (is_alloc_err_cleaner(fdf->img, fdf)
		|| is_alloc_err_cleaner(fdf->menu, fdf))
		exit(write(2, "Alloc error in the process\n", 27));
	fdf->img->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bpp, \
	&fdf->img->len, &fdf->img->endian);
	if (fdf->pressed.vector)
		print_center_vector_helper(fdf);
	if (!map_out_of_win(fdf))
		draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img, 0, 0);
	menu_put(fdf);
}

int	show_in_window(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (is_alloc_err_cleaner(fdf->mlx, fdf))
		return (0);
	fdf->window = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "FdF");
	if (is_alloc_err_cleaner(fdf->window, fdf))
		return (0);
	img_put(fdf);
	// mlx_hook(fdf->window, MOUSE_MOVE_UP | MOUSE_MOVE_DOWN, \
		// MOUSE_WHEEL_MASK, mouse_hook, fdf);
	mlx_mouse_hook(fdf->window, mouse_click_hook, fdf);
	(mlx_hook(fdf->window, KEY_PRESS, KEY_PRESS_MASK, key_press_hook, fdf));
	mlx_hook(fdf->window, KEY_RELEASE, KEY_RELEASE_MASK, key_release_hook, fdf);
	mlx_loop(fdf->mlx);
	return (1);
}
