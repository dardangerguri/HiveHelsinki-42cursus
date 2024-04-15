/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimal_printf.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:11:00 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 16:22:32 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_len(long nbr)
{
	int	length;

	length = 0;
	if (nbr == 0)
		length++;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

static char	*ft_unsigned_itoa(unsigned int number)
{
	unsigned long	nbr;
	int				len;
	char			*str;

	nbr = number;
	len = int_len(nbr);
	str = malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (nbr == 0)
	{
		str[0] = 48;
		str[1] = '\0';
		return (str);
	}
	while (nbr > 0)
	{
		str[len] = 48 + (nbr % 10);
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

int	unsigned_decimal_printf(unsigned int number, int fd)
{
	int		length;
	char	*numbr;

	length = 0;
	numbr = ft_unsigned_itoa(number);
	length = ft_putstr_fd(numbr, fd);
	free(numbr);
	return (length);
}
