/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:04:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2023/12/27 02:47:04 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_clean_used(t_printf *d)
{
	d->f_print = NULL;
	d->f_print_l = 0;
}

void	ft_clean(t_printf *d)
{
	free(d->start_p);
	free(d);
}
