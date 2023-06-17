/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:41:14 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/17 21:31:46 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstclear function is used to clear a linked list and free the memory occupied by its nodes.
 * It takes in a double pointer to the head of the list, 'lst', and a pointer to a function, 'del',
 * responsible for freeing the content of each node.
 *
 * The function checks if the 'lst' pointer is not NULL and enters a loop that continues
 * until either the list becomes empty or the 'del' function pointer is NULL.
 *
 * Inside the loop, the 'del' function is called with the content of the current node, and then the current node is freed.
 * The head pointer is updated to point to the next node.
 *
 * After the loop, '*lst' is set to 0 to indicate an empty list.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*old;

	if (lst != NULL)
	{
		while (*lst != NULL && del != NULL)
		{
			del((*lst)->content);
			old = *lst;
			*lst = old->next;
			free(old);
		}
		*lst = 0;
	}
}
