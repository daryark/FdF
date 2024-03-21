/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:43:53 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/27 02:52:42 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_ptr(t_printf *d, unsigned long long p)
{
	write(1, "0x", 2);
	d->len_printed += 2;
	if (!p)
	{
		write (1, "0", 1);
		d->len_printed += 1;
	}
	else
		ft_print_digits(d, p);
}
