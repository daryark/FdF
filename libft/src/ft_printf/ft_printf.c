/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 22:34:56 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/21 22:47:14 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_arg(t_printf *d, va_list args)
{
	d->curr_s++;
	ft_format_checker(d, args);
	ft_clean_used(d);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	t_printf	*data;
	int			res;

	if (!s)
		return (-1);
	data = ft_define_struct(s);
	va_start(args, s);
	while (*data->curr_s)
	{
		if (*data->curr_s == '%')
			ft_print_arg(data, args);
		else
		{
			write(1, data->curr_s++, 1);
			data->len_printed++;
		}
	}
	va_end(args);
	if (data->err)
		return (-1);
	res = data->len_printed;
	ft_clean(data);
	return (res);
}
