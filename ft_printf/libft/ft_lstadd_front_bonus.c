/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:53:37 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/17 21:22:18 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstadd_front function is used to add a new node, 'new', at the front of a linked list, 'lst'.
 * It takes in a double pointer to the head of the list, 'lst', and a pointer to the new node to be added, 'new'.
 *
 * In this function, the 'next' pointer of the new node, 'new->next', is assigned the value of the current head pointer, '*lst'.
 * This ensures that the new node points to the previous head node, effectively inserting it at the front of the list.
 *
 * Next, the head pointer '*lst' is updated to point to the new node, making it the new head of the list.
 *
 * This function assumes that the linked list is implemented using the t_list structure,
 * which typically consists of a data element and a pointer to the next node in the list.
 *
 * The ft_lstadd_front function provides a convenient way to prepend a new node to the beginning of a linked list,
 * maintaining the integrity and connectivity of the list.
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
