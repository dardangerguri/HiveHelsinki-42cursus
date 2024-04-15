/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:59:56 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/17 21:31:40 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * The ft_lstmap function is used to create a new linked list by applying a function, 'f',
 * to each node in the original linked list, 'lst'. It also takes in a function, 'del',
 * responsible for freeing the content of each node in case of an error.
 *
 * The function initializes two pointers, 'map' and 'head', to NULL.
 *
 * In a loop that continues while 'lst' is not NULL, the function creates a new node, 'map',
 * by calling ft_lstnew with the result of applying 'f' to the content of the current node.
 *
 * If 'map' is NULL, indicating a memory allocation failure,
 * the function clears the 'head' list using ft_lstclear and returns 'head' (which will be NULL).
 *
 * If 'map' is not NULL, it adds the new node, 'map', to the end of the 'head' list using ft_lstadd_back.
 *
 * The 'lst' pointer is updated to point to the next node in the original list,
 * and the loop continues until 'lst' becomes NULL.
 *
 * Once the loop exits, the 'head' pointer represents the head of the newly created list, and it is returned.
*/

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
