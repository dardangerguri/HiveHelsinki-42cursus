/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:59:45 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 20:24:54 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	input;
	int	output;

	if (argc == 5 && ft_strncmp(argv[0], "pipex", 5))
	{
		input = open(argv[1], O_RDONLY);
		output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (input == -1)
		{
			ft_putstr_fd("zsh: No such file or directory: ", 2);
			error_arg(input, output, argv[1]);
		}
		if (output == -1)
		{
			ft_putstr_fd("Error: Failed to open file ", 2);
			error_arg(input, output, argv[4]);
		}
		pipex(input, output, argv, envp);
	}
	else
	{
		ft_putstr_fd("ERROR: Not a valid number of arguments!\n", 2);
		ft_putstr_fd("DO: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
		exit(1);
	}
}
