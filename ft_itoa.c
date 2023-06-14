/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:46:19 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/14 17:35:30 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_itoa function converts an integer to a string representation.
 *
 * This function takes an integer 'n' and converts it into a string representation using ASCII characters.
 * The resulting string is dynamically allocated and must be freed by the caller to avoid memory leaks.
 *
 * The function first determines the length of the resulting string by counting the number of digits in 'n'.
 * It handles negative numbers by adding a '-' character at the beginning of the string and converting the absolute value of 'n' to a string.
 * If 'n' is zero, a single character '0' is returned as the string representation.
*/

static int	int_len(long n)
{
	int	length;

	length = 0;
	if (n == 0)
		length++;
	if (n < 0)
	{
		n = n * -1;
		length++;
	}
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

static char	*ifzero(char *s)
{
	s[0] = 48;
	s[1] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;

	nbr = n;
	len = int_len(nbr);
	str = malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	if (nbr == 0)
		return (ifzero(str));
	while (nbr > 0)
	{
		str[len] = 48 + (nbr % 10);
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
