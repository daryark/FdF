/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 03:58:20 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/19 19:57:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_num_len(int n, int sign)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	if (sign < 0)
		len++;
	return (len);
}

static int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*buf;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = ft_sign(n);
	if (sign < 0)
		n *= -1;
	len = ft_num_len(n, sign);
	buf = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!buf)
		return (NULL);
	while (len--)
	{
		if (len == 0 && sign < 0)
			buf[len] = '-';
		else
		{
			buf[len] = '0' + (n % 10);
			n /= 10;
		}
	}
	return (buf);
}
