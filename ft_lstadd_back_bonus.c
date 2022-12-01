/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:14:47 by dgerguri          #+#    #+#             */
/*   Updated: 2022/11/16 17:44:02 by dgerguri         ###   ########.fr       */
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
