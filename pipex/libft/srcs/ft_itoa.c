/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:46:19 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 19:00:13 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
