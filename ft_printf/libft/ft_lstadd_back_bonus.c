/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:14:47 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/17 21:20:03 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstadd_back function is used to add a new node, 'new', at the end of a linked list, 'lst'.
 * It takes in a double pointer to the head of the list, 'lst', and a pointer to the new node to be added, 'new'.
 *
 * The function first checks if the list is empty by evaluating if the head pointer, *lst, is NULL.
 * If the list is empty, it sets the head pointer to the new node,
 * effectively making it the first and only element in the list.
 *
 * If the list is not empty, it iterates through the list using the helper function ft_lstlast(*lst),
 * which returns a pointer to the last node in the list.
 * It assigns this pointer to a temporary variable, 'temporary_n'.
 *
 * Then, it assigns the 'next' pointer of the last node, 'temporary_n',
 * to point to the new node, 'new', effectively appending it to the end of the list.
 *
 * This function assumes that the linked list is implemented using the t_list structure,
 * which typically consists of a data element and a pointer to the next node in the list.
 * The last node in the list is identified by having a NULL 'next' pointer.
 *
 * Overall, this function provides a convenient way to add a new node at the end of a linked list,
 * maintaining the integrity and connectivity of the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temporary_n;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temporary_n = ft_lstlast(*lst);
		temporary_n->next = new;
	}
}
