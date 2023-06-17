/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:09:18 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/17 21:31:44 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstiter function is used to iterate over each node in a linked list and apply a given function, 'f',
 * to the content of each node.
 * It takes in a pointer to the head of the list, 'lst', and a pointer to a function, 'f',
 * that operates on the content of each node.
 *
 * The function enters a loop that continues as long as the 'lst' pointer is not NULL and the 'f' function pointer is not NULL.
 * Within the loop, the 'f' function is called with the content of the current node as the argument,
 * and then the 'lst' pointer is updated to point to the next node in the list.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL && f != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
