/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:19:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/12 23:55:49 by dyarkovs         ###   ########.fr       */
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
#  ifdef LINUX
#	 define WIN_WIDTH 3000
#  else
#   define WIN_WIDTH 1920
#  endif
# endif

# ifndef WIN_HEIGHT
#  ifdef LINUX
#	 define WIN_HEIGHT 2080
#  else
#   define WIN_HEIGHT 1300
#  endif
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <stdio.h> //!delete later
// # include <string.h>
// # include <errno.h>

# include "./keycode.h"
# include "libft/libft.h"
# include "libft/src/ft_printf/ft_printf.h"
# include "libft/src/get_next_line/get_next_line_bonus.h"

typedef struct s_map
{
	unsigned int	color;
	int				val;
	int				x;
	int				y;
}					t_map;

typedef struct s_img {
	void			*img;
	char			*addr;
	int				bpp; //bits per pixel
	int				len; //line len
	int				endian;
}					t_img;

typedef struct s_corner
{
	int				x_low;
	int				x_high;
	int				y_low;
	int				y_high;
}					t_corner;

typedef struct s_fdf
{
	int				width;
	int				height;
	t_corner		*corner;
	t_map			**map;

	void			*mlx;
	void			*window;
	t_img			*img;
	t_img			*menu;

	float			zoom;
	int				offset_x;
	int				offset_y;
	float			slope;
}					t_fdf;

void			print_map(t_fdf *fdf, int modificator); //!delete after finish the proj
void			print_center_vector_helper(t_fdf *fdf); //!delete after finish the proj
void			check_corners_red(t_fdf *fdf); //!delete after finish the proj
//process
int				ft_process(char	*file);
int				check_map_format(char *file);
void			parse_file(char *file, t_fdf *fdf);
int				show_in_window(t_fdf *fdf);
//utils
int				set_default_values(t_fdf *fdf);
void			map_size(char *file, t_fdf *fdf);
void			map_real_size(t_fdf *fdf);
void			reset_corner(t_corner *p);
void			init_map(t_fdf *fdf);
void			fill_point(char *str_point, t_fdf *fdf, int x, int y);
void			free_map(t_fdf *fdf);
void			swap_points(t_map *a, t_map *b);
unsigned int	ft_set_color(char *str);
unsigned int	interpolate_color(int i0, int i_curr, int i1, int clr0, int clr1);
int				open_error(int fd);
void			clean_all(t_fdf *fdf);
void			free_lines(char **line_arr);
//screen math
void			calc_zoom(t_fdf *fdf);
void			make_zoom(t_map *point, float zoom);
void			calc_offset(t_fdf *fdf);
void			set_offset(t_map *point, int offset_x, int offset_y);
void			center_map(t_fdf *fdf);
void			do_isometric(int *x, int *y, int z);
void			transform_map(t_fdf *fdf);
//mlx
void			img_put(t_fdf *fdf);
void			menu_put(t_fdf *fdf);
void			menu_text_put(t_fdf *fdf);
//mlx utils ?
void			draw_line_algorithm(t_map a, t_map b, t_fdf *fdf);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			fill_bg(int width, int height, t_map start, t_img *img);
//hooks
int				key_hook(int keycode, t_fdf *fdf);
int				mouse_hook(int keycode, t_fdf *fdf);

#endif