/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:52:44 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/03/27 02:54:07 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

//width -> spaces btw nums, + (2sp = 1 gap) for the last num, after which new line goes
// 2 spaces = 1 gap btw nums
// no need to count after 1 line
void	map_size(char *file, t_fdf *fdf)
{
	char	c[1];
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	while (read(fd, c, 1) > 0)
	{
		if (*c == '\n')
		{
			fdf->height++;
		}
		if (*c == ' ' && fdf->height == 0)
			fdf->width++;
	}
	fdf->width = (fdf->width + 2) / 2;
	close(fd);
}

//pass only valid input
//don't check for mixed case input: 85AaAa or not hexs
unsigned int	ft_set_color(char *str)
{
	int		nb;

	if (!str || !*str)
		return (0);
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

// int	arr_len(char **arr)
// {
// 	int	len;

// 	len = 0;
// 	ft_printf("arr_len enter\n");
// 	while (*arr != NULL)
// 		len++;
// 	return (len);
// }

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
