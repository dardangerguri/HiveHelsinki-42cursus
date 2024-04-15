/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:56:01 by dgerguri          #+#    #+#             */
/*   Updated: 2023/04/29 18:21:56 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	file_name_comp(char *file, char *ending)
{
	int	length;
	int	length_of_ending;

	length = ft_strlen(file);
	length_of_ending = ft_strlen(ending);
	if (ft_strncmp(file + length - length_of_ending, ending, length_of_ending))
		return (0);
	return (1);
}

void	file_validation(int argc, char **argv)
{
	if (argc == 1)
		error_message("There are no parameters!\n");
	if (argc == 2)
	{
		if (!file_name_comp(argv[1], ".ber"))
			error_message("The map is not a .ber file!\n");
	}
	else
		error_message("There is more than 1 parameter!\n");
}
