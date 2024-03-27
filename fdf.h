/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:19:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/27 02:32:35 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RESET_COLOR "\033[0m"

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "libft/libft.h"
# include "libft/src/ft_printf/ft_printf.h"
# include "libft/src/get_next_line/get_next_line_bonus.h"

// # ifdef	LINUX
// # include "mlx-linux/mlx.h"
// # else
// # include "mlx-osx/mlx.h"
// # endif
// # include <string.h>
// # include <errno.h>

typedef struct s_map
{
	unsigned int	color;
	int				val;
}	t_map;

typedef struct s_fdf
{
	int		width;
	int		height;
	t_map	**map;

	// void	*mlx_ptr;
	// void	*win_ptr;
}	t_fdf;

// t_fdf	*define_t_fdf(void);

//process
int				ft_process(char	*file);
int				check_map_format(char *file);
void			map_size(char *file, t_fdf *fdf);
//utils
// int		arr_len(char **arr);
unsigned int	ft_set_color(char *str);
void			parse_file(int fd, t_fdf *fdf);
void			init_map(t_fdf **fdf);
void			free_map(t_map **map);

//format and fill the map
// int		get_height(char *file);
// int		get_width(char *file);
// int		hex_to_decimal(char *s);
// void	fill_map(char *file, t_fdf **d);

#endif