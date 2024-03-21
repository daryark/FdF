/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:40:11 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/02/19 19:57:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	while (*lst)
	{
		t = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = t;
	}
	lst = NULL;
}

//? (*lst)->next
//! priority of -> vs *
//the reason of doint (*lst)->next when assign it to 't' is
// that the priority of the -> is higher than *
// so we technically get the *(lst->next) instead of (*lst) and then lst->next

//? (*(*lst).next)
// the other variant to write it like that (*(*lst)).next
// so it will dereference list pointer first 
// and go inside second pointer in the Node's next variable after