/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:40:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/28 16:46:58 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//pass only valid input
//don't check for mixed case input: 85AaAa or not hexs
unsigned int	ft_set_color(char *str)
{
	int		nb;

	if (!str || !*str)
		return (0);
	nb = 0;
	if (*str == '0' && *(str + 1) == 'x')
		str += 2;
	while ((*str >= '0' && *str <= '9')
		|| (*str >= 'a' && *str <= 'f')
		|| (*str >= 'A' && *str <= 'F'))
	{
		if (*str >= '0' && *str <= '9')
			nb = (nb * 16) + (*str - '0');
		else if (*str >= 'a' && *str <= 'f')
			nb = (nb * 16) + (*str - 'a' + 10);
		else
			nb = (nb * 16) + (*str - 'A' + 10);
		str++;
	}
	return (nb);
}

//sub-parse color from number, if there is color
//fills the row of nodes in map with the number and color values
static void	fill_row(t_map *row, char **arr)
{
	int		j;
	char	**point_arr;

	j = -1;
	while (arr[++j])
	{
		point_arr = ft_split(arr[j], ',');
		row[j].val = ft_atoi(point_arr[0]);
		row[j].color = ft_set_color(point_arr[1]);
	}
}

//if the map is not equal width * hight => not existing node will leave color hex as -1!
void	parse_file(int fd, t_fdf *fdf)
{
	int		i;
	char	*line;
	char	**line_arr;

	init_map(&fdf);
	if (!fdf->map)
		return ;
	i = -1;
	while (fdf->height > ++i)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_arr = ft_split(line, ' ');
		fill_row(fdf->map[i], line_arr);
	}
}
	//*split allocates the **row orf *words
	//*double split allocates the **mini_row of color and value
