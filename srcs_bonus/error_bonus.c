/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:55:02 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/13 17:05:35 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	error_message(char *message)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(message, 2);
	exit(1);
}

void	free_map(t_map **list)
{
	t_map	*temporary;

	if (list != NULL && (*list) != NULL)
	{
		while (*list != NULL)
		{
			temporary = (*list)->next;
			free(*list);
			*list = temporary;
		}
		*list = NULL;
	}
}

void	ft_error(t_map **list, t_map *line)
{
	if (list != NULL && *list != NULL)
		free_map(list);
	if (line != NULL)
		free(line);
	error_message("Memory allocation failed!\n");
}
