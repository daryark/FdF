/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:19:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/25 22:40:26 by dyarkovs         ###   ########.fr       */
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

# define MENU_W 350
# define PADDING	10

# ifndef WIN_W
#  ifdef LINUX
#	 define WIN_W 3000
#  else
#   define WIN_W 1920
#  endif
# endif

# ifndef WIN_H
#  ifdef LINUX
#	 define WIN_H 2080
#  else
#   define WIN_H 1300
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

typedef struct s_edge
{
	float			x_low;
	float			x_high;
	float			y_low;
	float			y_high;
	float			real_w;
	float			real_h;
}					t_edge;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp; //bits per pixel
	int				len; //line len
	int				endian;
}					t_img;

typedef struct s_pressed
{
	int				z;
	int				y;
	int				x;
	int				ctrl_l;
	int				minus;
	int				plus;
	int				up;
	int				down;
	int				left;
	int				right;
	int				vector;
	int				ortho;
	int				iso;
	int				r;
}					t_pressed;

typedef struct s_map
{
	unsigned int	color;
	float			val;
	float			x;
	float			y;
}					t_map;

typedef struct s_fdf
{
	t_map			**map;
	t_map			**map_orig;
	int				width;
	int				height;
	float			zheight;
	float			cx;
	float			cy;
	t_edge			edge;

	void			*mlx;
	void			*window;
	t_img			*img;
	t_img			*menu;

	float			slope;//! where is it used, why is it in main struct
	float			zoom;
	int				offset_x;
	int				offset_y;
	int				shift_x;
	int				shift_y;
	float			z_coef;
	float			angle_x;
	float			angle_y;
	float			angle_z;

	t_pressed		pressed; //when event triggered with multiple buttons
}					t_fdf;

void			print_map(t_fdf *fdf, int modificator);
void			print_center_vector_helper(t_fdf *fdf);
//process
int				ft_process(char	*file);
void			parse_file(char *file, t_fdf *fdf);
int				show_in_window(t_fdf *fdf);
//checkers, cleaners
int				check_map_format(char *file);
int				open_error(int fd);
int				is_alloc_err_cleaner(void *data, t_fdf *fdf);
void			free_map(t_map **map);
void			destroy_img(t_fdf *fdf);
void			clean_all(t_fdf *fdf);
void			free_lines(char **line_arr);
void			warning_put(t_fdf *fdf);
//set defaults
void			set_default_values(t_fdf *fdf);
void			initialize_pointers_null(t_fdf *fdf);
void			reset_screen_values(t_fdf *fdf);
void			reset_edge(t_edge *p);
void			reset_map(t_fdf *fdf);
//utils
void			map_size(char *file, t_fdf *fdf);
void			init_map(t_fdf *fdf);
void			map_dup(t_fdf *fdf);
void			fill_point(char *str_point, t_fdf *fdf, int x, int y);
unsigned int	ft_set_color(char *str);
int				minf(float a, float b);
int				maxf(float a, float b);
void			min_p(t_map *p, t_edge *edge);
void			max_p(t_map *p, t_edge *edge);
void			find_center(t_fdf *fdf);
void			map_z_height(t_fdf *fdf);
void			find_map_edges(t_fdf *fdf);
void			angle_normailze(float *angle);
//screen math
void			adjust_zoom(t_fdf *fdf);
void			make_zoom(t_map *point, float zoom);
void			zoom_map_to_win_size(t_fdf *fdf);
void			calc_offset(t_fdf *fdf);
void			set_offset(t_map *point, t_fdf *fdf);
void			center_map(t_fdf *fdf);
void			do_isometric(t_map *p, t_fdf *fdf);
void			transform_map(t_fdf *fdf);
void			transform_point(t_map *p, t_fdf *fdf);
//window
void			img_put(t_fdf *fdf);
void			menu_put(t_fdf *fdf);
void			draw_line_algorithm(t_map a, t_map b, t_fdf *fdf);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			fill_bg(int width, int height, t_map start, t_img *img);
void			redraw_img(t_fdf *fdf);
//hooks
int				key_press_hook(int keycode, t_fdf *fdf);
int				key_release_hook(int keycode, t_fdf *fdf);
int				mouse_click_hook(int keycode, int x, int y, t_fdf *fdf);
//events
void			zoom_event(t_fdf *fdf, int keycode);
void			move_event(t_fdf *fdf, int keycode);
void			hight_change_event(t_fdf *fdf, int keycode);
void			rotate_event(t_fdf *fdf, int keycode, float rot_num);
int				autorotate_event(t_fdf *fdf);
void			reset_event(t_fdf *fdf);
void			vector_show_event(t_fdf *fdf);
void			orthographic_view_event(t_fdf *fdf);
void			isometric_view_event(t_fdf *fdf);
void			close_event(t_fdf *fdf);
//event utils
void			do_shift(t_fdf *fdf);
void			angle_change(float *angle, int keycode, float rot_num);
int				map_out_of_win(t_fdf *fdf);
int				is_relevant_shift(t_fdf *fdf);
int				is_move_key(int keycode);
int				is_plus_minus_key(int keycode);
int				is_xyz_key(t_pressed pressed);
void			move_key_release(t_fdf *fdf, int keycode);
#endif