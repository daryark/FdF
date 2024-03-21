/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:09:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/27 19:47:21 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned int	ft_u_num_len(unsigned long long n, unsigned int b_l)
{
	unsigned int	len;

	len = 1;
	while (n >= b_l)
	{
		len++;
		n /= b_l;
	}
	return (len);
}

void	ft_utoa_base(unsigned long long n, t_base *b)
{
	if (n < b->b_l)
		write(1, &b->base[n], 1);
	else
	{
		ft_utoa_base((n / b->b_l), b);
		ft_utoa_base((n % b->b_l), b);
	}
}

void	ft_print_digits(t_printf *d, unsigned long long n)
{
	t_base	*s_base;

	s_base = ft_define_base(d);
	if (!s_base)
	{
		d->err = 1;
		return ;
	}
	d->f_print_l += ft_u_num_len(n, s_base->b_l);
	ft_utoa_base(n, s_base);
	free(s_base);
	d->len_printed += d->f_print_l;
}
