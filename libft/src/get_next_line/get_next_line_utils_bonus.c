/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:02:22 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/01/21 21:57:06 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	p = (void *)malloc(size * count);
	if (!p)
		return (NULL);
	i = 0;
	while (i < (count * size))
		*(unsigned char *)(p + i++) = '\0';
	return (p);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*buf;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (s1[++i])
		len++;
	buf = ft_calloc_gnl(sizeof(char), len + 1);
	if (!buf)
		return (NULL);
	i = -1;
	while (s1[++i])
		buf[i] = s1[i];
	return (buf);
}

//cleans curr node and moves head to the next lst
void	clean_node(t_gnl_lst **lst)
{
	t_gnl_lst	*tmp;

	tmp = (*lst)->next;
	free((*lst)->cont);
	free(*lst);
	*lst = tmp;
}

//if there is no list, the last will be NULL, so no \n char inside
int	find_newline(t_gnl_lst	*lst)
{
	int		i;

	while (lst)
	{
		i = -1;
		while (lst->cont[++i])
		{
			if (lst->cont[i] == '\n')
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}

int	lst_cont_len(t_gnl_lst *lst)
{
	int		size;
	char	*cont_ptr;

	size = 0;
	while (lst)
	{
		cont_ptr = lst->cont;
		while (*cont_ptr && *cont_ptr != '\n')
		{
			size++;
			cont_ptr++;
		}
		if (*cont_ptr && *cont_ptr == '\n')
			return (++size);
		lst = lst->next;
	}
	return (size);
}
