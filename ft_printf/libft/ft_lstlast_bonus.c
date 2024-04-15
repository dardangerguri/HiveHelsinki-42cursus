/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:00:14 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/17 21:29:56 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstlast function is used to retrieve the last node in a linked list.
 * It takes in a pointer to the head of the list, 'lst'.
 *
 * If the 'lst' pointer is NULL, indicating an empty list, the function returns NULL.
 *
 * Otherwise, the function enters a loop that continues until the 'next' pointer of the current node is NULL.
 * This loop allows the function to traverse the list by updating the 'lst' pointer to the next node.
 *
 * Once the loop exits, the 'lst' pointer represents the last node in the list, and it is returned by the function.
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
