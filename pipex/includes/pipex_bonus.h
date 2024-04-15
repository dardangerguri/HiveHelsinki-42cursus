/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:05 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 22:00:02 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/includes/libft.h"
# include <fcntl.h>

typedef struct s_files
{
	int	input;
	int	output;
	int	here_doc;
	int	pipes;
	int	pipes2;
	int	*pids;
}				t_files;

/* main bonus */
void	close_files(t_files *files, int type);

/* pipex bonus */
void	pipex_processes(t_files *files, char *argv, char **envp);

/* pipex here_doc */
void	pipex_here_doc(int argc, char **argv, char **envp);

/* pipex_split bonus */
char	**ft_split_pipex(char const *s, char c);

/* error bonus */
void	error_arg(t_files *files, char *message);
void	opening_files_error(t_files *files, char *message);
void	error_message(t_files *files, int *fd, char *message);
void	error_path(t_files *files, int *fd, char *cmd, char **paths_in_env);
void	free_array(char **array);

#endif
