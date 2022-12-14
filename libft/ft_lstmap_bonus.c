/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:59:56 by dgerguri          #+#    #+#             */
/*   Updated: 2022/11/17 18:19:24 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*head;

	head = NULL;
	while (lst != NULL)
	{
		map = ft_lstnew(f(lst->content));
		if (map == NULL)
		{
			ft_lstclear(&head, del);
			return (head);
		}
		ft_lstadd_back(&head, map);
		lst = lst->next;
	}
	return (head);
}
