/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:12:42 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/14 13:58:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//if the map is not equal width * hight
//=> not existing node will leave color hex as -1!
void	parse_file(char *file, t_fdf *fdf)
{
	int		i;
	int		j;
	char	*line;
	char	**line_arr;
	int		fd;

	fd = open(file, O_RDONLY);
	if (open_error(fd))
		return ;
	init_map(fdf);
	if (!fdf->map)
		return ;
	i = -1;
	while (fdf->height > ++i)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_arr = ft_split(line, ' ');
		free(line);
		j = -1;
		while (line_arr[++j])
			fill_point(line_arr[j], fdf, j, i);
		// free_lines(line_arr);
	}
}

int	ft_process(char	*file)
{
	t_fdf	fdf;

	if (set_default_values(&fdf))
		return (1);
	map_size(file, &fdf);
	parse_file(file, &fdf);
	if (!fdf.map)
	{
		clean_all(&fdf);
		return (1);
	}
	transform_map(&fdf);
	center_map(&fdf);
	if (!show_in_window(&fdf))
		return (1);
	clean_all(&fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_map_format(argv[1]))
		{
			ft_putendl_fd(RED "Wrong format and/or permissions" RE, 2);
			return (1);
		}
		if (ft_process(argv[1]))
			return (1);
	}
	else
		ft_putendl_fd(YELLOW "Add exactly one file to read from!" RE, 2);
	return (0);
}
