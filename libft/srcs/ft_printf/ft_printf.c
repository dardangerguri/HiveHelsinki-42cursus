/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:36:14 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 16:26:16 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	string_printf(char *string, int fd)
{
	int	ret;

	if (string == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ret = ft_putstr_fd(string, fd);
	return (ret);
}

static int	decimal_printf(int number, int fd)
{
	int		length;
	char	*numbr;

	length = 0;
	numbr = ft_itoa(number);
	length = ft_putstr_fd(numbr, fd);
	free(numbr);
	return (length);
}

static int	type(va_list argument, char index, int fd)
{
	int	length;

	length = 0;
	if (index == 'c')
		length = ft_putchar_fd(va_arg(argument, int), fd);
	else if (index == 's')
		length = string_printf(va_arg(argument, char *), fd);
	else if (index == 'p')
	{
		ft_putstr_fd("0x", fd);
		index = 'x';
		length = 2 + hexadecimal_printf(va_arg(argument, unsigned long), \
		index, fd);
	}
	else if (index == 'd' || index == 'i')
		length = decimal_printf(va_arg(argument, int), fd);
	else if (index == 'u')
		length = unsigned_decimal_printf(va_arg(argument, unsigned int), fd);
	else if (index == 'x' || index == 'X')
		length = hexadecimal_printf(va_arg(argument, unsigned int), index, fd);
	else if (index == '%')
		length = ft_putchar_fd('%', fd);
	else
		length = ft_putchar_fd(index, fd);
	return (length);
}

int	ft_printf(int fd, const char *input, ...)
{
	va_list	argument;
	int		i;
	int		length_of_printed_characters;

	va_start (argument, input);
	i = 0;
	length_of_printed_characters = 0;
	while (input[i] != '\0')
	{
		if (input[i] != '\0' && input[i] != '%')
		{
			ft_putchar_fd(input[i], fd);
			i++;
			length_of_printed_characters++;
		}
		if (input[i] == '%')
		{
			i++;
			length_of_printed_characters += type(argument, input[i], fd);
			i++;
		}
	}
	va_end (argument);
	return (length_of_printed_characters);
}
