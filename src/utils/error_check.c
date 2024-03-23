/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:14:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/23 23:15:02 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../fdf.h"

int	check_map_format(char *file)
{
	int		len;
	int		i;
	char	*format;

	if (open(file, O_RDONLY) < 0)
		return (1);
	format = ".fdf";
	i = ft_strlen(format);
	len = ft_strlen(file);
	while (format[--i])
	{
		len--;
		if (file[len] != format[i])
			return (1);
	}
	//!if this "name.smth.fdf" is valid format also ?
	// len--;
	// while (file[len] && file[len] != '.')
	// 	len--;
	// if (file[len])
	// 	return (1);
	return (0);
}
