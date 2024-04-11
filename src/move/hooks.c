/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:45:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/11 02:41:23 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int    mouse_hook(int keycode, t_fdf *fdf)
{
    (void)fdf;
	ft_printf("hello from my hook, %d\n", keycode);
    return (0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
    if (keycode == 65307)
        mlx_destroy_window(fdf->mlx, fdf->window);
    else
        ft_printf("hello from my hook, %d\n", keycode);
    return (0);
}
