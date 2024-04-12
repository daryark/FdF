/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:14:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/12 17:10:21 by dyarkovs         ###   ########.fr       */
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

//zoom  2
void	set_default_values(t_fdf *fdf)
{
	fdf->height = 0;
	fdf->width = 0;
    fdf->corner = malloc(sizeof(t_corner));
	fdf->zoom = 2.0;
    fdf->offset_x = 0;
    fdf->offset_y = 0;
	fdf->slope = 0.0;
	fdf->map = NULL;
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->img = NULL;
	fdf->menu = NULL;
}
void	reset_corner(t_corner *p)
{
	p->x_low = INT_MAX;
	p->y_low = INT_MAX;
	p->x_high = INT_MIN;
	p->y_high = INT_MIN;
}

unsigned int	ft_set_color(char *str)
{
	int		nb;

	if (!str || !*str)
		return (0xffffff);
	nb = 0;
	if (*str == '0' && *(str + 1) == 'x')
		str += 2;
	while ((*str >= '0' && *str <= '9')
		|| (*str >= 'a' && *str <= 'f')
		|| (*str >= 'A' && *str <= 'F'))
	{
		if (*str >= '0' && *str <= '9')
			nb = (nb * 16) + (*str - '0');
		else if (*str >= 'a' && *str <= 'f')
			nb = (nb * 16) + (*str - 'a' + 10);
		else
			nb = (nb * 16) + (*str - 'A' + 10);
		str++;
	}
	return (nb);
}
