/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:24:39 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/19 19:53:05 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../../libft.h"

typedef struct s_base
{
	char			*base;
	unsigned int	b_l;
}	t_base;

typedef struct s_printf
{
	char	*curr_s;
	char	*start_p;
	int		len_printed;
	char	*f_print;
	int		f_print_l;
	int		err;
}	t_printf;

int				ft_printf(const char *s, ...);

t_printf		*ft_define_struct(const char *s);
void			*ft_define_base(t_printf *d);

void			ft_format_checker(t_printf *d, va_list args);

void			ft_print_d_i(t_printf *d, int n);
void			ft_utoa_base(unsigned long long n, t_base *b);
unsigned int	ft_u_num_len(unsigned long long n, unsigned int b_l);
void			ft_print_u_x(t_printf *d, unsigned int n);
void			ft_print_ptr(t_printf *d, unsigned long long p);
void			ft_print_c(t_printf *d, int c);
void			ft_print_s(t_printf *d, char *s);

void			ft_print_digits(t_printf *d, unsigned long long n);

void			ft_clean_used(t_printf *d);
void			ft_clean(t_printf *d);

#endif