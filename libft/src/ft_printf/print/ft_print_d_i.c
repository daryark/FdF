/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 00:26:49 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/27 02:48:55 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_d_i(t_printf *d, int n)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		write (1, "-", 1);
		d->f_print_l += 1;
		nb *= -1;
	}
	ft_print_digits(d, (unsigned long long)nb);
}
