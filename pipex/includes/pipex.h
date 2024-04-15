/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:05 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/02 17:13:40 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <fcntl.h>

/* pipex */
void	pipex(int input, int output, char **argv, char **envp);

/* error */
void	free_array(char **array);
void	handle_error_path(char *cmd, char **paths_in_env);
void	error_arg(int intput, int output, char *message);
void	error_message(int input, int output, int *fd, char *message);

/* pipex_split */
char	**ft_split_pipex(char const *s, char c);

#endif
