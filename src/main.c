/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:12:42 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/27 02:57:17 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
			(*fdf)->map[i][j].color = 0;
			(*fdf)->map[i][j].val = 0;
		}
	}
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

// void	parse_line(int fd, t_fdf *fdf, int line)
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

void	print_map(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	while (fdf->height > ++i)
	{
		j = -1;
		while (fdf->width > ++j)
			ft_printf(" %d,%d ", fdf->map[i][j].val, fdf->map[i][j].color);
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
	map_size(file, &fdf);
	ft_printf("w: %d, h: %d\n", fdf.width, fdf.height);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	parse_file(fd, &fdf);
	close (fd);
	if (!fdf.map)
		return (1);
	print_map(&fdf); //just printing staff, remove after
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
	
	ft_printf(GREEN "---------------\n%s\n" RESET_COLOR, argv[1]);
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
