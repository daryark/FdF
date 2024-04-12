/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:45:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/12 15:16:37 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void    move_img(t_fdf *fdf, char direction)
{
    int i;
    int j;

    i = -1;
    mlx_clear_window(fdf->mlx, fdf->window);
    while (++i < fdf->height)
    {
        j = -1;
        while (++j < fdf->width)
        {
            if (direction == 'u')
                fdf->map[i][j].y -= 30;
            if (direction == 'd')
                fdf->map[i][j].y += 30;
            if (direction == 'l')
                fdf->map[i][j].x -= 30;
            if (direction == 'r')
                fdf->map[i][j].x += 30;
        }
    }
    img_put(fdf);
}

int    mouse_hook(int keycode, t_fdf *fdf)
{
    (void)fdf;
	ft_printf("hello from my hook, %d\n", keycode);
    return (0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
    if (keycode == CLOSE_BTN || keycode == HK_ESC)
    {
        mlx_destroy_image(fdf->mlx, fdf->img->img);
	    mlx_destroy_image(fdf->mlx, fdf->menu->img);
        mlx_destroy_window(fdf->mlx, fdf->window);
        (void)fdf->mlx;
        free(fdf->mlx);
        free_map(fdf);
        exit(EXIT_SUCCESS);
    }
    else if (keycode == HK_UP)
        move_img(fdf, 'u');
    else if (keycode == HK_DOWN)
        move_img(fdf, 'd');
    else if (keycode == HK_LEFT)
        move_img(fdf, 'l');
    else if (keycode == HK_RIGHT)
        move_img(fdf, 'r');
    else
        ft_printf("hello from my hook, %d\n", keycode);
    return (0);
}
