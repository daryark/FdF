/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:45:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/11 04:28:23 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void    move_up(t_fdf *fdf)
{
    int i;
    int j;

    i = -1;
    mlx_clear_window(fdf->mlx, fdf->window);
    while (++i < fdf->height)
    {
        j = -1;
        while (++j < fdf->width)
            fdf->map[i][j].y -= 50;
    }
    menu_put(fdf);
    img_put(fdf);
    mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->menu->img, 0, 0);
    menu_text_put(fdf);
}

void    move_down(t_fdf *fdf)
{
    int i;
    int j;

    i = -1;
    mlx_clear_window(fdf->mlx, fdf->window);
    while (++i < fdf->height)
    {
        j = -1;
        while (++j < fdf->width)
            fdf->map[i][j].y += 50;
    }
    img_put(fdf);
    menu_put(fdf);
    mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->menu->img, 0, 0);
    menu_text_put(fdf);
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
        mlx_destroy_window(fdf->mlx, fdf->window);
    else if (keycode == HK_UP)
        move_up(fdf);
    else if (keycode == HK_DOWN)
        move_down(fdf);
    else
        ft_printf("hello from my hook, %d\n", keycode);
    return (0);
}
