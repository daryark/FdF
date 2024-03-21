/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:17:06 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/19 19:57:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u;

	if (n < 0)
	{
		u = -n;
		ft_putchar_fd('-', fd);
	}
	else
		u = n;
	if (u < 10)
		ft_putchar_fd((u + '0'), fd);
	else
	{
		ft_putnbr_fd((u / 10), fd);
		ft_putnbr_fd((u % 10), fd);
	}
}

//? unisigned int is done only for INT_MIN
//* to not make it as a single case for print
//as with unisgned int we have a bigger range of nums and it is enough
//to handle (INT_MAX + 1) in case of transforming min to positive number.