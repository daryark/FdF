/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:29:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/26 14:26:34 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	check_map_format(char *file)
{
	int		len;
	int		i;
	char	*format;
	int		fd;

	fd = open(file, O_RDONLY);
	if (open_err(fd))
		return (1);
	format = ".fdf";
	i = ft_strlen(format);
	len = ft_strlen(file);
	while (--i >= 0)
	{
		len--;
		if (file[len] != format[i])
		{
			close(fd);
			return (1);
		}
	}
	close(fd);
	return (0);
}

int	open_err(int fd)
{
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int	is_alloc_err_cleaner(void *data, t_fdf *fdf)
{
	if (data == NULL)
	{
		clean_all(fdf);
		return (1);
	}
	return (0);
}

void	warning_put(t_fdf *fdf)
{
	if (fdf->zoom == 1)
		mlx_string_put(fdf->mlx, fdf->window, 30, WIN_H - 30, 0x928686, \
			"Map smallest size, zoom = 1.0");
	else if (fdf->zoom == 1000)
		mlx_string_put(fdf->mlx, fdf->window, 30, WIN_H - 30, 0x928686, \
			"Map biggest size, zoom = 1000.0");
}
