/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:14:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/23 17:11:04 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	minf(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

int	maxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	min_p(t_map *p, t_edge *edge)
{
	edge->x_low = minf(p->x, edge->x_low);
	edge->y_low = minf(p->y, edge->y_low);
}

void	max_p(t_map *p, t_edge *edge)
{
	edge->x_high = maxf(p->x, edge->x_high);
	edge->y_high = maxf(p->y, edge->y_high);
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
