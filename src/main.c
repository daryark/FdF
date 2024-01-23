/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:12:42 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/01/21 22:05:33 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void	read_file(char	*file)
// {
// 	int		fd;
// 	char	*n_l;

// 	fd = open("test_maps/42.fdf", O_RDONLY);
// 	while (1)
// 	{
// 		n_l = get_next_line(fd);
// 		if (!n_l)
// 			break;
// 		printf("%s", n_l);
// 	}
	// void	*mlx;
	// void	*mlx_win;
	// t_data	img;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// int i = 0;
	// while (i++ < 100)
	// 	my_mlx_pixel_put(&img, 10 + i, 5+i, 0x0099FF99);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
// }

void	get_height(char *file, t_fdf **d)
{
	int	fd;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd))
		(*d)->height++;
	printf("height: %d\n", (*d)->height);
	close(fd);
}

void	ft_process(char	*file)
{
	t_fdf	*d;

	get_height(file, &d);
	// d->width = get_width(file);
	// d->map = (int **)malloc(sizeof(int *) * d->height);
	// fill_map(file, &d);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_process(argv[1]);
	else
		ft_printf("Add exactly one file to read from!\n");
	return (0);
}
