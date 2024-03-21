/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:24:46 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/19 19:57:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *src, const char *srch, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*srch)
		return ((char *)src);
	i = 0;
	while (src[i] && i < len)
	{
		j = 0;
		while (src[i + j] == srch[j] && (i + j) < len)
		{
			j++;
			if (!srch[j])
				return ((char *)(src + i));
		}
		i++;
	}
	return (NULL);
}
