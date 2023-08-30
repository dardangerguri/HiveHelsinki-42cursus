/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:04:30 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/12 17:12:56 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_putstr_fd function writes a string to a file descriptor.
 *
 * This function writes the null-terminated string 's' to the file descriptor 'fd' using the write system call.
 * If 's' is NULL, the function returns 0.
 *
 * It returns the number of bytes written, which should be the length of the string if successful.
 *
 * Note: While the libft subject requires this to be a void function (not returning anything), however,
 * for future projects it is better to define it as int to handle potential errors and return -1 if needed.
 */

int	ft_putstr_fd(char *s, int fd)
{
	int	len;
	int	ret;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	ret = write(fd, s, len);
	return (ret);
}
