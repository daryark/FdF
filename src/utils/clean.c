/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:26:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/14 22:58:17 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	free_map(t_fdf *fdf, int option)
{
	int	i;

	i = 0;
	if (option == 'm')
	{
		while (fdf->map[i] && i < fdf->height)
		free(fdf->map[i++]);
		free(fdf->map);
		fdf->map = NULL;
	}
	else if (option == 'o')
	{
		while (fdf->map_orig[i] && i < fdf->height)
		free(fdf->map_orig[i++]);
		free(fdf->map_orig);
		fdf->map_orig = NULL;
	}
}

void	clean_all(t_fdf *fdf)
{
	if (fdf->map != NULL)
		free_map(fdf, 'm');
	if (fdf->map_orig != NULL)
		free_map(fdf, 'o');
	if (fdf->corner != NULL)
		free (fdf->corner);
	printf("%p, menu: %p\n", fdf->img->img, fdf->menu->img);
	if (fdf->img != NULL && fdf->img->img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->img->img);
	if (fdf->menu != NULL && fdf->menu->img != NULL)
		mlx_destroy_image(fdf->mlx, fdf->menu->img);
	if (fdf->window != NULL)
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
