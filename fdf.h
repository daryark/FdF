/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:19:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/01/21 22:07:26 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# include "MiniLibX/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <time.h>
# include <stdio.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**map;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	ft_process(char	*file);
void	get_height(char *file, t_fdf **d);

#endif