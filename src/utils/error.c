/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:29:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/14 17:33:36 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//if map is valid - return opened fd num
// else return -1, fd still open
int	check_map_format(char *file)
{
	int		len;
	int		i;
	char	*format;
	int		fd;

	fd = open(file, O_RDONLY);
	if (open_error(fd))
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

int	open_error(int fd)
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
