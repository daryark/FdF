/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:52:44 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/02 14:23:08 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	free_map(t_map **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

//init the empty map
void	init_map(t_fdf **fdf)
{
	int		i;
	int		j;

	(*fdf)->map = (t_map **)malloc(sizeof(t_map *) * (*fdf)->height);
	if (!(*fdf)->map)
		return ;
	i = -1;
	while (++i < (*fdf)->height)
	{
		j = 0;
		(*fdf)->map[i] = (t_map *)malloc(sizeof(t_map) * (*fdf)->width);
		if (!(*fdf)->map[i])
		{
			free_map((*fdf)->map);
			return ;
		}
		j = -1;
		while (++j < (*fdf)->width)
		{
			(*fdf)->map[i][j].color = (unsigned int)(-1);
			(*fdf)->map[i][j].val = 0;
		}
	}
}
//(unsigned int)(-1) leads to be the largest value of unsigned int
// after type cast, so the hex color can never reach this value. 
//Means i can define it that way to see if the point exists
//=> has been filled at least with 0, if no color specified.

//?if i will do the map with different line length ->
//*than change the formula until find the longest line
//count width in first line
//then get hight from amount of other lines returned
void	map_size(char *file, t_fdf *fdf)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (*line)
	{
		if (*line != ' ' && (*(line + 1) == ' ' || *(line + 1) == '\n'))
			fdf->width++;
		line++;
	}
	while (line != NULL)
	{
		fdf->height++;
		line = get_next_line(fd);
	}
	close(fd);
}
