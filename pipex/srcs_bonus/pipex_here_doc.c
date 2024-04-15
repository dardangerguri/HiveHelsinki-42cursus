/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:23:34 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 22:01:10 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	wait_process(t_files *files)
{
	int	i;

	i = 0;
	while (i <= files->pipes2)
	{
		waitpid(files->pids[i], NULL, 0);
		i++;
	}
	free(files->pids);
}

void	input_file_opening(t_files *files)
{
	files->input = open(".here_doc.tmp", O_RDONLY);
	if (files->input == -1)
	{
		unlink(".here_doc.tmp");
		error_arg(files, ".here_doc.tmp");
	}
}

static void	here_doc_file(char **argv, t_files *files)
{
	size_t		limiter_len;
	char		*buf;

	limiter_len = ft_strlen(argv[2]);
	files->here_doc = open(".here_doc.tmp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (files->here_doc == -1)
		error_arg(files, "Error: Failed to open file: .here_doc.tmp");
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		buf = get_next_line(STDIN_FILENO);
		if (buf == NULL)
			error_arg(files, "Error: Get next line failed!");
		if (ft_strlen(buf) == (limiter_len + 1)
			&& (ft_strncmp(buf, argv[2], limiter_len) == 0))
			break ;
		ft_putstr_fd(buf, files->here_doc);
		free(buf);
	}
	free(buf);
	close(files->here_doc);
	input_file_opening(files);
}

void	pipex_here_doc(int argc, char **argv, char **envp)
{
	t_files	files;
	int		i;

	files.pipes = argc - 5;
	files.pipes2 = argc - 5;
	files.pids = malloc(sizeof(int) * (files.pipes + 1));
	if (files.pids == NULL)
		error_arg(&files, "Error: Memory allocation failed!");
	files.output = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (files.output == -1)
	{
		ft_putstr_fd("Error: Failed to open file ", 2);
		error_arg(&files, argv[argc - 1]);
	}
	here_doc_file(argv, &files);
	if (dup2(files.input, STDIN_FILENO) == -1)
		error_arg(&files, "Error: Dup2 failed!");
	i = 3;
	while (files.pipes >= 0)
	{
		pipex_processes(&files, argv[i++], envp);
		files.pipes--;
	}
	wait_process(&files);
	close_files(&files, 2);
}
