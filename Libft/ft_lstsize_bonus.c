/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:28:14 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/17 21:34:50 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstsize function is used to calculate the size of a linked list,
 * which represents the number of nodes in the list.
 * It takes in a pointer to the head of the list, 'lst'.
 *
 * If the 'lst' pointer is NULL, indicating an empty list, the function returns 0.
 *
 * Otherwise, the function initializes a variable, 'size', to 0,
 * which will serve as the counter for the number of nodes.
 *
 * In a loop that continues while 'lst' is not NULL, the 'lst' pointer is updated to point to the next node in the list,
 * and the 'size' variable is incremented by 1.
 *
 * Once the loop exits, the 'size' variable represents the number of nodes in the list,
 * and it is returned by the function.
*/

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (lst == NULL)
		return (0);
	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
