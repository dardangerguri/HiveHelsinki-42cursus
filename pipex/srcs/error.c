/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:33:07 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/02 16:58:04 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_arg(int input, int output, char *message)
{
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	if (input != -1)
		close(input);
	if (output != -1)
		close(output);
	exit(1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	error_message(int input, int output, int *fd, char *message)
{
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	if (input != -1)
		close(input);
	if (output != -1)
		close(output);
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	exit(1);
}

void	handle_error_path(char *cmd, char **paths_in_env)
{
	free(cmd);
	free_array(paths_in_env);
	error_message(0, 0, 0, "Error: Memory allocation failed!");
}
