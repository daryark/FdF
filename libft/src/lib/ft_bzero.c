/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:58:50 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/19 19:57:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_bzero(void *p, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		*(unsigned char *)(p + i++) = '\0';
}

//void pointer is used to say 'any type', used in function where
// we wanna refer to a memory in more general sense, than some specific type
//size_t - unsigned long