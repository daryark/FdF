/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:19:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/18 17:01:13 by dyarkovs         ###   ########.fr       */
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

# define MENU_WIDTH 350

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

typedef struct s_img
{
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
	int				real_w;
	int				real_h;
}					t_corner;

typedef struct s_fdf
{
	int				width;
	int				height;
	t_corner		*corner;
	t_map			**map;
	t_map			**map_orig;

	void			*mlx;
	void			*window;
	t_img			*img;
	t_img			*menu;
	int				err;

	float			slope;
	float			zoom;
	int				offset_x;
	int				offset_y;
	int				shift_x;
	int				shift_y;
	float			z_coef;
	float			angle_x;
	float			angle_y;
	float			angle_z;

	int				pre_event; //when event triggered with two buttons
	int				prev_mv;
}					t_fdf;

void			print_map(t_fdf *fdf, int modificator); //!delete after finish the proj
void			print_center_vector_helper(t_fdf *fdf); //!delete after finish the proj
void			check_corners_green(t_fdf *fdf); //!delete after finish the proj
//process
int				ft_process(char	*file);
void			parse_file(char *file, t_fdf *fdf);
int				show_in_window(t_fdf *fdf);
//checkers, cleaners
int				check_map_format(char *file);
int				open_error(int fd);
int				is_alloc_err_cleaner(void *data, t_fdf *fdf);
void			free_map(t_map **map, int height);
void			destroy_img(t_fdf *fdf);
void			clean_all(t_fdf *fdf);
void			free_lines(char **line_arr);
void			warning_put(t_fdf *fdf);
//utils
int				set_default_values(t_fdf *fdf);
void			reset_corner(t_corner *p);
void			init_map(t_fdf *fdf);
void			fill_point(char *str_point, t_fdf *fdf, int x, int y);
void			swap_points(t_map *a, t_map *b);
unsigned int	ft_set_color(char *str);
unsigned int	interpolate_color(int i0, int i_curr, int i1, int clr0, int clr1);
void			map_dup(t_fdf *fdf);
void			reset_map(t_fdf *fdf);
//screen math
void			map_size(char *file, t_fdf *fdf);
void			map_real_size(t_fdf *fdf);
void			adjust_zoom(t_fdf *fdf);
void			make_zoom(t_map *point, float zoom);
void			zoom_map_to_win_size(t_fdf *fdf);
void			calc_offset(t_fdf *fdf);
void			set_offset(t_map *point, int offset_x, int offset_y);
void			center_map(t_fdf *fdf);
void			do_isometric(int *x, int *y, int *z, t_fdf *fdf);
void			transform_map(t_fdf *fdf);
//window
void			img_put(t_fdf *fdf);
void			menu_put(t_fdf *fdf);
void			menu_text_put(t_fdf *fdf);
void			draw_line_algorithm(t_map a, t_map b, t_fdf *fdf);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			fill_bg(int width, int height, t_map start, t_img *img);
void			redraw_img(t_fdf *fdf);
//hooks
int				key_press_hook(int keycode, t_fdf *fdf);
int				key_release_hook(int keycode, t_fdf *fdf);
// int				mouse_hook(int keycode, t_fdf *fdf);
//events
void			zoom_event(t_fdf *fdf, int keycode);
void			move_event(t_fdf *fdf, int keycode);
void			hight_change_event(t_fdf *fdf, int keycode);
void			rotate_event(t_fdf *fdf, int keycode);
void			close_event(t_fdf*fdf);
//event utils
void			move_img(t_fdf *fdf, int keycode);

#endif