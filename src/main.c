/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:12:42 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/03 21:02:02 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//returns 1, if error happened. else - 0
void	ft_process(char	*file, t_fdf *fdf)
{
	int		fd;

	fd = check_map_format(file);
	if (fd < 0)
	{
		close(fd);
		ft_putendl_fd(RED "Wrong format and/or permissions" RE, 2);
		return ;
	}
	map_size(file, fdf);
	parse_file(fd, fdf);
	close (fd);
	if (!fdf->map)
		return ;
	print_map(fdf, 0); //just printing staff, remove after
	show_in_window(fdf);
	return ;
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf.height = 0;
	fdf.width = 0;
	fdf.zoom = 1;
	fdf.slope = 0.0;
	fdf.map = NULL;
	fdf.mlx = NULL;
	fdf.window = NULL;
	fdf.img = NULL;
	fdf.menu = NULL;
	if (argc == 2)
		ft_process(argv[1], &fdf);
	else
		ft_putendl_fd(YELLOW "Add exactly one file to read from!" RE, 2);
	
	ft_printf(GREEN "---------------\n%s\n" RE, argv[1]);//just printing staff, remove after
	return (0);
}
