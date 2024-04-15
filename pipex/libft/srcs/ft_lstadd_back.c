/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:14:47 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 19:03:01 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
