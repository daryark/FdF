/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:19:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/01/30 14:29:12 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "prev_projects/libft/libft.h"
# include "prev_projects/ft_printf/ft_printf.h"
# include "prev_projects/get_next_line/get_next_line.h"

# include "MiniLibX/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
// # include <string.h>
// # include <errno.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define MAGENTA "\033[0;35m"
#define RESET_COLOR "\033[0m"

typedef struct s_map
{
	int	hex;
	int	z;
}	t_map;

typedef struct s_fdf
{
	int		width;
	int		height;
	t_map	**map;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

// t_fdf	*define_t_fdf(void);

int		ft_process(char	*file);
int		get_height(char *file);
int		get_width(char *file);
int		hex_to_decimal(char *s);
void	fill_map(char *file, t_fdf **d);

#endif