/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:14:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/04/15 22:49:45 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	set_default_values(t_fdf *fdf)
{
	fdf->height = 0;
	fdf->width = 0;
	fdf->zoom = 50.0;
	fdf->offset_x = 0;
	fdf->offset_y = 0;
	fdf->shift_x = 0;
	fdf->shift_y = 0;
	fdf->slope = 0.0;
	fdf->map = NULL;
	fdf->map_orig = NULL;
	fdf->corner = malloc(sizeof(t_corner));
	if (is_alloc_err_cleaner(fdf->corner, fdf))
		return (1);
	fdf->img = NULL;
	fdf->menu = NULL;
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->err = 0;
	fdf->z_event = 0;
	fdf->z_coef = 1;
	return (0);
}

void	reset_corner(t_corner *p)
{
	p->x_low = INT_MAX;
	p->y_low = INT_MAX;
	p->x_high = INT_MIN;
	p->y_high = INT_MIN;
	p->real_w = 0;
	p->real_h = 0;
}
void	reset_map(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->height)
	{
		j = -1;
		while (++j < fdf->width)
		{
			fdf->map[i][j].color = fdf->map_orig[i][j].color;
			fdf->map[i][j].val = fdf->map_orig[i][j].val;
			fdf->map[i][j].x = fdf->map_orig[i][j].x;
			fdf->map[i][j].y = fdf->map_orig[i][j].y;
		}
	}
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

