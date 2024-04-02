/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:19:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/02 14:31:13 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RE "\033[0m"

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
// # include <string.h>
// # include <errno.h>

# include "libft/libft.h"
# include "libft/src/ft_printf/ft_printf.h"
# include "libft/src/get_next_line/get_next_line_bonus.h"

# ifdef LINUX
#  include "mlx-linux/mlx.h"
# else
#  include "mlx-osx/mlx.h"
# endif

typedef struct s_map
{
	unsigned int	color;
	int				val;
	int				x;
	int				y;
}	t_map;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fdf
{
	int		width;
	int		height;
	t_map	**map;

	void	*mlx;
	void	*window;
	t_img	*img;
}	t_fdf;

// t_fdf	*define_t_fdf(void);

void			print_map(t_fdf *fdf); //!delete after finish the proj
//process
int				ft_process(char	*file);
int				check_map_format(char *file);
void			map_size(char *file, t_fdf *fdf);
//utils
unsigned int	ft_set_color(char *str);
void			parse_file(int fd, t_fdf *fdf);
void			init_map(t_fdf **fdf);
void			free_map(t_map **map);
//mlx
void			show_in_window(t_fdf *fdf);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			img_put(t_fdf *fdf);
void  		 	draw_line_algorithm(t_map p0, t_map p1, t_img *img);

//format and fill the map
// int		get_height(char *file);
// int		get_width(char *file);
// int		hex_to_decimal(char *s);
// void	fill_map(char *file, t_fdf **d);

#endif