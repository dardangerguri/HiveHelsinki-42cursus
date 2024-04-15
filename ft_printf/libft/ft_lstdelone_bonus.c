/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:02:50 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/17 21:31:45 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstdelone function is used to delete a single node from a linked list and free the memory occupied by that node.
 * It takes in a pointer to the node to be deleted, 'lst', and a pointer to a function, 'del',
 * responsible for freeing the content of the node.
 *
 * The function checks if both the 'lst' pointer and the 'del' function pointer are not NULL.
 * If so, it calls the 'del' function with the content of the node as the argument, and then frees the node itself.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
