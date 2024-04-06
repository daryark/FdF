/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:19:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/06 04:22:39 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RE "\033[0m"

# ifdef LINUX
#  include "mlx-linux/mlx.h"
# else
#  include "mlx-osx/mlx.h"
# endif

# define MENU_WIDTH 300

# ifndef WIN_WIDTH
#	define WIN_WIDTH 1920 //1920
# endif

# ifndef WIN_HEIGHT
#	define WIN_HEIGHT 1080 //1300
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
// # include <string.h>
// # include <errno.h>

# include "libft/libft.h"
# include "libft/src/ft_printf/ft_printf.h"
# include "libft/src/get_next_line/get_next_line_bonus.h"

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
	int		bpp; //bits per pixel
	int		len; //line len
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
	t_img	*menu;

	int		zoom;
	int		offset_x;
	int		offset_y;
	float	slope;
}	t_fdf;


// typedef struct s_interpolate
// {

// }
// typedef struct s_color
// {
// 	int	r;
// 	int	g;
// 	int b;
// }	t_color;

void			print_map(t_fdf *fd, int modificator); //!delete after finish the proj
void			print_center_vector_helper(t_fdf *fdf); //!delete after finish the proj
//process
int			ft_process(char	*file);
int				check_map_format(char *file);
void			parse_file(int fd, t_fdf *fdf);
//utils
void			set_default_values(t_fdf *fdf);
void			map_size(char *file, t_fdf *fdf);
void			init_map(t_fdf **fdf);
void			free_map(t_map **map);
void		    swap_points(t_map *p0, t_map *p1);
unsigned int	ft_set_color(char *str);
//screen math
void			calc_zoom(t_fdf *fdf);
void			make_zoom(t_map *point, int zoom);
void			calc_offset(t_fdf *fdf);
void			set_offset(t_map *point, int offset_x, int offset_y);
void    		isometric(int *x, int *y, int z);
//mlx
void			show_in_window(t_fdf *fdf);
void			img_put(t_fdf *fdf);
void			menu_put(t_fdf *fdf);
void   			menu_text_put(t_fdf *fdf);
//mlx utils ?
void  		 	draw_line_algorithm(t_map p0, t_map p1, t_fdf *fdf);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void   			fill_bg(int width, int height, t_map start, t_img *img);

//format and fill the map
// int		get_height(char *file);
// int		get_width(char *file);
// int		hex_to_decimal(char *s);
// void	fill_map(char *file, t_fdf **d);

#endif