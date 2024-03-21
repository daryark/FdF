/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:52:44 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/01/26 01:11:06 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


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
