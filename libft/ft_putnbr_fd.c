/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:34:49 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/12 17:14:52 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_putnbr_fd function writes an integer as a string to a file descriptor.
 *
 * This function converts the integer 'n' into a string representation and writes it to the file descriptor 'fd'
 * using the write system call. It supports both positive and negative integers.
 */

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else
	{
		if (n < 0)
		{
			sign = -1;
			ft_putchar_fd('-', fd);
			n = n * sign;
		}
		if (n < 10)
			ft_putchar_fd(n + 48, fd);
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
