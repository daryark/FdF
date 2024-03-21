/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 03:26:42 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/19 19:57:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*output_l;
	void	*content;

	output_l = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&output_l, del);
			return (NULL);
		}
		ft_lstadd_back(&output_l, new_node);
		lst = lst->next;
	}
	return (output_l);
}

//f: The address of the function used to iterate on the list. 
//(function that does smth on each element of the list, 
//each single el need to be passed on one iteration)

// del: The address of the function used to delete
// the content of a node if needed.