/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:12:42 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/24 20:42:02 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map	**parse_map(char *file, t_fdf *fdf)
{
	int		fd;
	int		i;
	char	*line;
	char	**arr;
	char	**one_arr;
	t_map	node;
	t_map	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_height(fd, fdf);
	ft_printf ("height: %d\n", fdf->height);
	i = -1;
	line = NULL;
	arr = NULL;
	one_arr = NULL;
	while (line != NULL && fdf->height < ++i)
	{
		line = get_next_line(fd);
		arr = ft_split(line, ' ');
		fdf->width = arr_len(arr);
		//do the fn, where inisde will be created a static map (2 dimention arr)
		// pass args width, hight, return initiated map with empty t_map structs
		// definition: t_map **init_map(width, height);
		// ! hm, if i want to use map all over the process, not being allocated
		// ! but done static, i need to return the sizes on that step, and give
		// ! the control back to process fn, to have this as an upper fn and
		// ! have the ability to pass map to inner fn inside the same scope ??
		// ! ask about these and the scope from chat????
		//* also don't forget to write definitions into header
		while (*arr)
		{
			one_arr = ft_split(*arr, ',');
			if (one_arr[1] && !is_valid_color(one_arr[1]))
				return (NULL);
			else
				ft_printf("color is valid\n");
		node.val = ft_atoi(one_arr[0]);
		node.color = ft_atoi_hex(one_arr[0]);

		}
	}
	//?split allocates the **row orf *words
	//?double split allocates the **mini_row of color and value

	return (NULL);
}

int	ft_process(char	*file)
{
	t_fdf	fdf;

	fdf.height = 0;
	fdf.width = 0;
	fdf.map = parse_map(file, &fdf);
	// t_fdf	*node;

	// node = malloc(sizeof(t_fdf));
	// if (!node)
	// 	return (1);
	// node->height = get_height(file);
	// node->width = get_width(file);
	// fill_map(file, &node);
	// ft_printf(MAGENTA "height: %d\nwidth: %d\n" RESET_COLOR, node->height, node->width);
	// int r = -1;
	// // ft_printf("[z: %d, h: %d] [z: %d, h: %d] [z: %d, h: %d] \n", node->map[0][0].z, node->map[0][0].hex, node->map[0][1].z, d->map[0][1].hex, d->map[0][2].z, d->map[0][2].hex);
	// while (++r < node->height)
	// {
	// 	int p = -1;
	// 	ft_printf("%node->", (r + 1));
	// 	while (++p < node->width)
	// 		ft_printf("[z: %d, h: %d] ",node->map[r][p].z, node->map[r][p].hex);
	// 	ft_printf("\n");
	// }
	ft_printf(GREEN "---------------\n%s\n" RESET_COLOR, file);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_map_format(argv[1]))
		{
			ft_putendl_fd(RED "Wrong format and/or permissions" RESET_COLOR, 2);
			return (0);
		}
		if (ft_process(argv[1]))
			ft_putendl_fd(RED "Error occured in the process" RESET_COLOR, 2);
	}
	else
		ft_putendl_fd(YELLOW "Add ONE file to read from!" RESET_COLOR, 2);
	return (0);
}


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

// int	get_height(char *file)
// {
// 	int	fd;
// 	int	h;

// 	fd = open(file, O_RDONLY);
// 	h = 0;
// 	while (get_next_line(fd) > 0)
// 		h++;
// 	close(fd);
// 	return (h);
// }

// int	get_width(char *file)
// {
// 	int		fd;
// 	int		w;
// 	char	**arr;

// 	fd = open(file, O_RDONLY);
// 	arr = ft_split(get_next_line(fd), ' ');
// 	w = 0;
// 	while (arr[w] != NULL)
// 		w++;
// 	close(fd);
// 	return (w);
// }

// int	hex_to_decimal(char *s)
// {
// 	int	len;
// 	int	base;
// 	int	n;

// 	base = 1;
// 	n = 0;
// 	len = ft_strlen(s);
// 	while (s[--len])
// 	{
// 		if (s[len] >= '0' && s[len] <= '9')
// 			n += (s[len] - 48) * base;
// 		else if (s[len] >= 'A' && s[len] <= 'F')
// 			n += (s[len] - 55) * base;
// 		else if (s[len] >= 'a' && s[len] <= 'f')
// 			n += (s[len] - 55 - 32) * base;
// 		base *= 16;
// 	}
// 	return (n);
// }

// void	fill_map(char *file, t_fdf **d)
// {
// 	int		fd;
// 	int		ln;
// 	int		p;
// 	char	**row;
// 	char	**point;

// 	fd = open(file, O_RDONLY);
// 	(*d)->map = (t_map **)malloc(sizeof(t_map *) * (*d)->height);
// 	// if (!(*d)->map)
// 	// 	return ;
// 	ln = -1;
// 	while (++ln < (*d)->height)
// 	{
// 		(*d)->map[ln] = (t_map *)malloc(sizeof(t_map) * (*d)->width);
// 		// if (!(*d->map[ln]))
// 		// 	return ;
// 		row = ft_split((char const *)get_next_line(fd), ' ');
// 		ft_printf("\nrow 1: [%d] [%d] [%d] \n",  row[0], row[1], row[2]);
// 		// ft_printf("\nrow 1: [z: %d, h: %d] [z: %d, h: %d] [z: %d, h: %d] \n",  (*d)->map[0][0].z, (*d)->map[0][0].hex, (*d)->map[0][1].z, (*d)->map[0][1].hex, (*d)->map[0][2].z, (*d)->map[0][2].hex);
// 		p = -1;
// 		while (++p < (*d)->width)
// 		{
// 			point = ft_split((char const *)(row[p]), ',');
// 			((*d)->map[ln][p]).z = ft_atoi(point[0]);
// 			((*d)->map[ln][p]).hex = 0;
// 			if (point[1])
// 				((*d)->map[ln][p]).hex = hex_to_decimal(point[1]);
// 		}
// 	}
// 	close(fd);
// }
// int	check_map_format(char *file)
// {
// 	int		len;
// 	int		i;
// 	char	*format;

// 	if (open(file, O_RDONLY) < 0)
// 		return (1);
// 	format = ".fdf";
// 	i = ft_strlen(format);
// 	len = ft_strlen(file);
// 	while (format[--i])
// 	{
// 		len--;
// 		if (file[len] != format[i])
// 			return (1);
// 	}
// 	return (0);
// }