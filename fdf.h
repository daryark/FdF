/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:19:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/23 23:28:35 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"
#define RESET_COLOR "\033[0m"

# include "libft/libft.h"
# include "libft/src/ft_printf/ft_printf.h"
# include "libft/src/get_next_line/get_next_line_bonus.h"

# ifdef	LINUX
# include "mlx-linux/mlx.h"
# else
# include "mlx-osx/mlx.h"
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
// # include <string.h>
// # include <errno.h>

// typedef struct s_map
// {
// 	int	hex;
// 	int	z;
// }	t_map;

// typedef struct s_fdf
// {
// 	int		width;
// 	int		height;
// 	t_map	**map;

// 	void	*mlx_ptr;
// 	void	*win_ptr;
// }	t_fdf;

// t_fdf	*define_t_fdf(void);

//process
int	check_map_format(char *file);
int		ft_process(char	*file);

//format and fill the map
// int		get_height(char *file);
// int		get_width(char *file);
// int		hex_to_decimal(char *s);
// void	fill_map(char *file, t_fdf **d);

#endif