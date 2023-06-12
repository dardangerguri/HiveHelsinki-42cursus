/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:11:50 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/12 17:13:48 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_putendl_fd function writes a string followed by a newline character to a file descriptor.
 *
 * This function writes the null-terminated string 's' to the file descriptor 'fd' using the write system call.
 * After writing the string, it appends a newline character ('\n') to the file descriptor.
 *
 */

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	c;

	i = 0;
	if (s != '\0')
	{
		while (s[i] != '\0')
		{
			c = s[i];
			write(fd, &c, 1);
			i++;
		}
		c = '\n';
		write(fd, &c, 1);
	}
}
