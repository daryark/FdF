/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:12:42 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/01 23:07:03 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//just printing staff, remove after the whole function!!!
void	print_map(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (fdf->height > ++i)
	{
		j = -1;
		while (fdf->width > ++j)
		{
			if (fdf->map[i][j].color == (unsigned int)(-1))
				ft_printf(RED);
			ft_printf(" %d,%d " RE, fdf->map[i][j].val, fdf->map[i][j].color);
		}
		ft_printf("\n");
	}
}

//returns 1, if error happened. else - 0
int	ft_process(char	*file)
{
	t_fdf	fdf;
	int		fd;

	fdf.height = 0;
	fdf.width = 0;
	fdf.mlx = NULL;
	fdf.window = NULL;
	map_size(file, &fdf);
	ft_printf("w: %d, h: %d\n", fdf.width, fdf.height);//just printing staff, remove after
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	parse_file(fd, &fdf);
	close (fd);
	if (!fdf.map)
		return (1);
	print_map(&fdf); //just printing staff, remove after
	show_in_window(&fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		//!!commented only when use fsanitize!!
		// if (check_map_format(argv[1]))
		// {
		// 	ft_putendl_fd(RED "Wrong format and/or permissions" RE, 2);
		// 	return (0);
		// }
		//!
		if (ft_process(argv[1]))
			ft_putendl_fd(RED "Error occured in the process" RE, 2);
	}
	else
		ft_putendl_fd(YELLOW "Add ONE file to read from!" RE, 2);
	
	ft_printf(GREEN "---------------\n%s\n" RE, argv[1]);//just printing staff, remove after
	return (0);
}