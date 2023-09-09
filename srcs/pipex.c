/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:01:27 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 20:24:26 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*path(char *cmd, char **paths_in_env)
{
	int		i;
	char	*slash;
	char	*path_in_env;

	i = 0;
	while (paths_in_env[i])
	{
		slash = ft_strjoin(paths_in_env[i], "/");
		if (slash == NULL)
			handle_error_path(cmd, paths_in_env);
		path_in_env = ft_strjoin(slash, cmd);
		if (path_in_env == NULL)
		{
			free(slash);
			handle_error_path(cmd, paths_in_env);
		}
		free(slash);
		if (access(path_in_env, X_OK | F_OK) == 0)
			return (path_in_env);
		free(path_in_env);
		i++;
	}
	return (NULL);
}

static char	*get_path(char *cmd, char **envp)
{
	char	**paths_in_env;
	char	*path_env;
	int		i;

	i = 0;
	if (access(cmd, X_OK | F_OK) == 0)
		return (cmd);
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths_in_env = ft_split(envp[i] + 5, ':');
	if (paths_in_env == NULL)
	{
		free(cmd);
		error_message(0, 0, 0, "Error: Memory allocation failed!");
	}
	path_env = path(cmd, paths_in_env);
	free_array(paths_in_env);
	return (path_env);
}

static void	second_child_process(int *fd, int output, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	close(fd[1]);
	if (dup2(output, STDOUT_FILENO) == -1)
		error_message(0, output, fd, "Error: Dup2 failed!");
	close(output);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_message(0, output, fd, "Error: Dup2 failed!");
	cmd = ft_split_pipex(argv[3], ' ');
	if (cmd == NULL)
		error_message(0, output, fd, "Error: Memory allocation failed!");
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_array(cmd);
		ft_putstr_fd("zsh: command not found: ", 2);
		error_message(0, output, fd, argv[3]);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_array(cmd);
		error_message(0, output, fd, "Error: Execeve failed!");
	}
}

static void	child_process(int *fd, int input, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	close(fd[0]);
	if (dup2(input, STDIN_FILENO) == -1)
		error_message(input, 0, fd, "Error: Dup2 failed!");
	close(input);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error_message(input, 0, fd, "Error: Dup2 failed!");
	cmd = ft_split_pipex(argv[2], ' ');
	if (cmd == NULL)
		error_message(input, 0, fd, "Error: Memory allocation failed!");
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_array(cmd);
		ft_putstr_fd("zsh: command not found: ", 2);
		error_message(input, 0, fd, argv[2]);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_array(cmd);
		error_message(input, 0, fd, "Error: Execeve failed!");
	}
}

void	pipex(int input, int output, char **argv, char **envp)
{
	int		fd[2];
	pid_t	id;
	pid_t	id2;

	if (pipe(fd) == -1)
		error_message(input, output, fd, "Error: Pipe creation failed!");
	id = fork();
	if (id == -1)
		error_message(input, output, fd, "Error: Fork failed!");
	if (id == 0)
		child_process(fd, input, argv, envp);
	id2 = fork();
	if (id2 == -1)
		error_message(input, output, fd, "Error: Fork failed!");
	if (id2 == 0)
		second_child_process(fd, output, argv, envp);
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
	close(input);
	close(output);
}
