/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:14:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/03 15:36:19 by dyarkovs         ###   ########.fr       */
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
	if (fd < 0)
		return (-1);
	format = ".fdf";
	i = ft_strlen(format);
	len = ft_strlen(file);
	while (--i >= 0)
	{
		len--;
		if (file[len] != format[i])
			return (-1);
	}
	return (fd);
}
