/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:12:42 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/12 17:43:04 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//if the map is not equal width * hight
//=> not existing node will leave color hex as -1!
void	parse_file(int fd, t_fdf *fdf)
{
	int		i;
	int		j;
	char	*line;
	char	**line_arr;

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
		j = -1;
		while (line_arr[++j])
			fill_point(line_arr[j], fdf, j, i);
	}
}

int	ft_process(char	*file)
{
	t_fdf	fdf;
	int		fd;

	fd = check_map_format(file);
	if (fd < 0)
	{
		close(fd);
		ft_putendl_fd(RED "Wrong format and/or permissions" RE, 2);
		return (1);
	}
	set_default_values(&fdf);
	map_size(file, &fdf);
	parse_file(fd, &fdf);
	close (fd);
	if (!fdf.map)
		return (1);
	fdf.zoom = 400;//temp value, delete later
	transform_map(&fdf);
    center_map(&fdf);
	printf("centered again map\n"); //just print
	print_map(&fdf, 1); //tmp print map, delete later
	if (show_in_window(&fdf))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_process(argv[1]))
			return (1);
	}
	else
		ft_putendl_fd(YELLOW "Add exactly one file to read from!" RE, 2);
	
	ft_printf(GREEN "---------------\n%s\n" RE, argv[1]);//just printing staff, remove after
	return (0);
}
