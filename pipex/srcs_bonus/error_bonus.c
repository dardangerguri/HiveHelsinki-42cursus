/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:33:07 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/10 18:19:20 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	error_arg(t_files *files, char *message)
{
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	if (files->input != -1)
		close(files->input);
	if (files->output != -1)
		close(files->output);
	if (files->here_doc != -1)
		close(files->here_doc);
	if (files->pids != NULL)
		free(files->pids);
	exit(1);
}

void	opening_files_error(t_files *files, char *message)
{
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	if (files->input != -1)
		close(files->input);
	if (files->output != -1)
		close(files->output);
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

void	error_message(t_files *files, int *fd, char *message)
{
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	if (files->input != -1)
		close(files->input);
	if (files->output != -1)
		close(files->output);
	if (files->here_doc != -1)
		close(files->here_doc);
	if (files->pids != NULL)
		free(files->pids);
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	exit(1);
}

void	error_path(t_files *files, int *fd, char *cmd, char **paths_in_env)
{
	free(cmd);
	free_array(paths_in_env);
	error_message(files, fd, "Error: Memory allocation failed!");
	exit(1);
}
