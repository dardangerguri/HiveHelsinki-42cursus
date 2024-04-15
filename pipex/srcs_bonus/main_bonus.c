/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:59:45 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 22:03:21 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	file_opening(int argc, char **argv, t_files *files)
{
	files->input = open(argv[1], O_RDONLY);
	files->output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (files->input == -1)
	{
		ft_putstr_fd("zsh: No such file or directory: ", 2);
		opening_files_error(files, argv[1]);
	}
	if (files->output == -1)
	{
		ft_putstr_fd("Error: Failed to open file ", 2);
		opening_files_error(files, argv[argc - 1]);
	}
}

void	close_files(t_files *files, int type)
{
	close(files->input);
	close(files->output);
	if (type == 1)
		free(files->pids);
	if (type == 2)
		unlink(".here_doc.tmp");
}

static void	pipex(int argc, char **argv, char **envp)
{
	t_files	files;
	int		i;

	file_opening(argc, argv, &files);
	files.pipes = argc - 4;
	files.pipes2 = argc - 4;
	files.pids = malloc(sizeof(int) * (files.pipes + 1));
	if (files.pids == NULL)
		error_arg(&files, "Error: Memory allocation failed!");
	if (dup2(files.input, STDIN_FILENO) == -1)
		error_arg(&files, "Error: Dup2 failed!");
	i = 2;
	while (files.pipes >= 0)
	{
		pipex_processes(&files, argv[i], envp);
		files.pipes--;
		i++;
	}
	i = 0;
	while (i <= files.pipes2)
	{
		waitpid(files.pids[i], NULL, 0);
		i++;
	}
	close_files(&files, 1);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5 && ft_strncmp(argv[0], "pipex", 5))
	{
		if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		{
			if (argc < 6)
			{
				ft_putstr_fd("ERROR: Not a valid number of arguments!\n", 2);
				ft_putstr_fd("DO: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
				exit(1);
			}
			pipex_here_doc(argc, argv, envp);
		}
		else
			pipex(argc, argv, envp);
	}
	else
	{
		ft_putstr_fd("ERROR: Not a valid number of arguments!\n", 2);
		ft_putstr_fd("DO: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
		exit(1);
	}
}
