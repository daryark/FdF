/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:14:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/19 23:12:14 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void angle_normailze(int *angle)
{
	while (!(*angle <= 360 && *angle >= 0))
	{
		if (*angle < 0)
			*angle += 360;
		else
			*angle -= 360;
	}
	printf("angle: %d\n", *angle);
}

unsigned int ft_set_color(char *str)
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

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
void	min_p()