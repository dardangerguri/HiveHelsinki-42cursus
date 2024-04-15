/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:41:14 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 19:03:19 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
