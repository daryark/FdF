/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:40:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/03 19:27:53 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"


//?CHECK THE OPACITY?
//*add check for opacity if i will extend with Y Syaosin algorithm
//pass only valid input
//don't check for mixed case input: 85AaAa or not hexs
unsigned int	ft_set_color(char *str)
{
	int		nb;

	if (!str || !*str)
		return (0xffffff);
		// return (0xaff1f1fd); //grey
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

static void	fill_point(char *str_point, t_map *point, int x, int y)
{
	char	**point_arr;

	point_arr = ft_split(str_point, ',');
	point->val = ft_atoi(point_arr[0]);
	point->color = ft_set_color(point_arr[1]);
	point->x = x;
	point->y = y;
}

//if the map is not equal width * hight => not existing node will leave color hex as -1!
void	parse_file(int fd, t_fdf *fdf)
{
	int		i;
	int		j;
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
		j = -1;
		while (line_arr[++j])
			fill_point(line_arr[j], &fdf->map[i][j], j, i);
	}
}
//second loop goes until the length of the parsed map exists
//even if it is less then the width

	//*split allocates the **row orf *words
	//*double split allocates the **mini_row of color and value
