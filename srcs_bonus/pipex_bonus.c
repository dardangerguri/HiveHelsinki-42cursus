/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:01:27 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 22:02:02 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static char	*path(char *cmd, char **paths_in_env, t_files *files, int *fd)
{
	int		i;
	char	*slash;
	char	*path_in_env;

	i = 0;
	while (paths_in_env[i])
	{
		slash = ft_strjoin(paths_in_env[i], "/");
		if (slash == NULL)
			error_path(files, fd, cmd, paths_in_env);
		path_in_env = ft_strjoin(slash, cmd);
		if (path_in_env == NULL)
		{
			free(slash);
			error_path(files, fd, cmd, paths_in_env);
		}
		free(slash);
		if (access(path_in_env, X_OK | F_OK) == 0)
			return (path_in_env);
		free(path_in_env);
		i++;
	}
	return (NULL);
}

static char	*get_path(char *cmd, char **envp, t_files *files, int *fd)
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
		error_message(files, fd, "Error: Memory allocation failed!");
	}
	path_env = path(cmd, paths_in_env, files, fd);
	free_array(paths_in_env);
	return (path_env);
}

static void	child_process(t_files *files, int *fd, char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	close(fd[0]);
	if (dup2(files->input, STDIN_FILENO) == -1)
		error_message(files, fd, "Error: Dup2 failed!");
	close(files->input);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error_message(files, fd, "Error: Dup2 failed!");
	cmd = ft_split_pipex(argv, ' ');
	if (cmd == NULL)
		error_message(files, fd, "Error: Memory allocation failed!");
	path = get_path(cmd[0], envp, files, fd);
	if (!path)
	{
		free_array(cmd);
		ft_putstr_fd("zsh: command not found: ", 2);
		error_message(files, fd, argv);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_array(cmd);
		error_message(files, fd, "Error: Execeve failed!");
	}
}

static void	last_child_process(t_files *files, int *fd, char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	close(fd[1]);
	if (dup2(files->output, STDOUT_FILENO) == -1)
		error_message(files, fd, "Error: Dup2 failed!");
	close(files->output);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error_message(files, fd, "Error: Dup2 failed!");
	cmd = ft_split_pipex(argv, ' ');
	if (cmd == NULL)
		error_message(files, fd, "Error: Memory allocation failed!");
	path = get_path(cmd[0], envp, files, fd);
	if (!path)
	{
		free_array(cmd);
		ft_putstr_fd("zsh: command not found: ", 2);
		error_message(files, fd, argv);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_array(cmd);
		error_message(files, fd, "Error: Execeve failed!");
	}
}

void	pipex_processes(t_files *files, char *argv, char **envp)
{
	int			fd[2];
	pid_t		id;
	static int	i;

	if (pipe(fd) == -1)
		error_message(files, fd, "Error: Pipe creation failed!");
	id = fork();
	if (id == -1)
		error_message(files, fd, "Error: Fork failed!");
	if (id == 0 && files->pipes != 0)
		child_process(files, fd, argv, envp);
	if (id == 0 && files->pipes == 0)
		last_child_process(files, fd, argv, envp);
	else
	{
		files->pids[i] = id;
		i++;
		close(fd[0]);
		close(fd[1]);
	}
}
