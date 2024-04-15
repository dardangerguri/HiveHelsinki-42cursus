/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:08:06 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/12 17:11:03 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_putchar_fd function writes a single character to a file descriptor.
 *
 * This function writes the character 'c' to the file descriptor 'fd' using the write system call.
 * It returns the number of bytes written, which should be 1 if successful.
 *
 * Note: While the libft subject requires this to be a void function (not returning anything), however,
 * for future projects it is better to define it as int to handle potential errors and return -1 if needed.
*/

int	ft_putchar_fd(char c, int fd)
{
	int	ret;

	ret = write(fd, &c, 1);
	return (ret);
}
