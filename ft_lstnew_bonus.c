/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:03:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/17 21:33:07 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_lstnew function is used to create a new node for a linked list.
 * It takes in a pointer to the content that will be stored in the node.
 *
 * The function allocates memory for a new node using malloc and the size of the t_list structure.
 * If the memory allocation fails (new_node is NULL), the function returns NULL.
 *
 * If the memory allocation is successful, the content pointer is assigned to the content field of the new node,
 * and the next field is set to NULL.
 *
 * Finally, the new_node pointer is returned, representing the newly created node.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
