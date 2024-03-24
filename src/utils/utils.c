/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:52:44 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/24 20:32:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	map_height(int fd, t_fdf *fdf)
{
	char	line[1];

	++fdf->height;
	while (read(fd, line, 1))
	{
		if (*line == '\n')
			fdf->height++;
	}
}

int	is_valid_color(char *str)
{
	int	type;

	type = 0;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'F')
		{
			if (type < 0)
				return (0);
			type = 1;
		}
		else if (*str >= 'a' && *str <= 'f')
		{
			if (type > 0)
				return (0);
			type = -1;
		}
		str++;
	}
	return (1);
}
//pass only valid input
//or add checker function before: is_valid_color(...) ⤴️
//don't check for mixed case input: 85AaAa
int	ft_atoi_hex(char *str)
{
	int		sign;
	int		nb;

	sign = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9'
		|| *str >= 'a' && *str <= 'f'
		|| *str >= 'A' && *str <= 'F')
	{
		nb = (nb * 16) + (*str - '0');
		str++;
	}
	return (nb * sign);
}

int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (*arr != NULL)
		len++;
	return (len);
}

// int	ft_error_handle(char *base)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (!base[0] || !base[1])
// 		return (1);
// 	while (base[i])
// 	{
// 		j = i + 1;
// 		if (base[i] == 43 || base[i] == 45)
// 			return (1);
// 		if (base[i] < 32 || base[i] > 126)
// 			return (1);
// 		while (base[j])
// 		{
// 			if (base[i] == base[j])
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// unsigned long long	ft_atoi_base(char *s, char *base)
// {
// 	int					b_l;
// 	int					s_l;
// 	unsigned long long	n;
// 	int					b;

// 	if (ft_error_handle(base))
// 		return (1);
// 	b_l = ft_strlen(base);
// 	s_l = ft_strlen(s);
// 	b = 1;
// 	while (s_l >= 0)
// 	{
// 		if (s[s_l] >= '0' && s[s_l] <= '9')
// 			n += (s[s_l] - 48) * b;
// 		else if (b_l == 16 && s[s_l] >= 'A' && s[s_l] <= 'F')
// 			n += (s[s_l] - 55) * b;
// 		else if (b_l == 16 && s[s_l] >= 'a' && s[s_l] <= 'f')
// 			n += (s[s_l] - 55 - 32) * b;
// 		b *= base;
// 		s_l--;
// 	}
// 	return (n);
// }
