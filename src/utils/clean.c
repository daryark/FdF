/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:26:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/26 01:54:26 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	free_map(t_map **map)
{
	int	i;

	i = -1;
	while (map && map[++i] && i < 19)
		free(map[i]);
	free(map);
	map = NULL;
}

void	destroy_img(t_fdf *fdf)
{
	if (fdf->img && fdf->img->img)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		fdf->img = NULL;
	}
	if (fdf->menu && fdf->menu->img)
	{
		mlx_destroy_image(fdf->mlx, fdf->menu);
		fdf->menu = NULL;
	}
}

void	clean_all(t_fdf *fdf)
{
	if (fdf->map)
		free_map(fdf->map);
	if (fdf->map_orig)
		free_map(fdf->map_orig);
	destroy_img(fdf);
	if (fdf->window)
		mlx_destroy_window(fdf->mlx, fdf->window);
	if (fdf->mlx)
	{
		(void)fdf->mlx;
		free(fdf->mlx);
	}
}

void	free_lines( char **line_arr)
{
	int	i;

	i = -1;
	while (line_arr[++i])
		free(line_arr[i]);
	free(line_arr);
	line_arr = NULL;
}
