/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:52:44 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/26 14:50:59 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//init the empty map
void	init_map(t_fdf *fdf)
{
	int		i;
	int		j;

	fdf->map = malloc(sizeof(t_map *) * fdf->height);
	if (!fdf->map)
		return ;
	i = -1;
	while (++i < fdf->height)
	{
		j = 0;
		fdf->map[i] = malloc(sizeof(t_map) * fdf->width);
		if (is_alloc_err_cleaner(fdf->map[i], fdf))
			return ;
		j = -1;
		while (++j < fdf->width)
		{
			fdf->map[i][j].color = (unsigned int)(-1);
			fdf->map[i][j].val = 0;
		}
	}
}
//(unsigned int)(-1) leads to be the largest value of unsigned int
// after type cast, so the hex color can't be that high =>
// if it stays (unsigned int)(-1), point doesn't exist. 

void	fill_point(char *str_point, t_fdf *fdf, int x, int y)
{
	char	**point_arr;

	point_arr = ft_split(str_point, ',');
	fdf->map[y][x].val = ft_atoi(point_arr[0]);
	fdf->map[y][x].color = ft_set_color(point_arr[1]);
	free_lines(point_arr);
	fdf->map[y][x].x = x;
	fdf->map[y][x].y = y;
}

//count width in first line
//then get hight from amount of other lines returned
void	map_size(char *file, t_fdf *fdf)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (open_err(fd))
		return ;
	line = get_next_line(fd);
	if (!line)
		exit(ft_printf(RED "Not valid file\n" RE));
	i = -1;
	while (line[++i])
	{
		if ((line[i] == ' ' && line[i - 1] != ' ')
			|| (line[i] != ' ' && !line[i + 1]))
			fdf->width++;
	}
	while (line != NULL)
	{
		fdf->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	reset_map(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			fdf->map[i][j].color = fdf->map_orig[i][j].color;
			fdf->map[i][j].val = fdf->map_orig[i][j].val;
			fdf->map[i][j].x = fdf->map_orig[i][j].x;
			fdf->map[i][j].y = fdf->map_orig[i][j].y;
		}
	}
}

void	map_dup(t_fdf *fdf)
{
	int		i;
	int		j;

	fdf->map_orig = malloc(sizeof(t_map *) * fdf->height);
	if (is_alloc_err_cleaner(fdf->map_orig, fdf))
		return ;
	i = -1;
	while (++i < fdf->height)
	{
		fdf->map_orig[i] = malloc(sizeof(t_map) * fdf->width);
		if (is_alloc_err_cleaner(fdf->map_orig[i], fdf))
			return ;
		j = -1;
		while (++j < fdf->width)
		{
			fdf->map_orig[i][j].color = fdf->map[i][j].color;
			fdf->map_orig[i][j].val = fdf->map[i][j].val;
			fdf->map_orig[i][j].x = fdf->map[i][j].x;
			fdf->map_orig[i][j].y = fdf->map[i][j].y;
		}
	}
}
