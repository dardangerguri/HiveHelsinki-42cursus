/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:47:54 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 17:46:34 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_memcmp function compares the first 'n' bytes of memory areas 's1' and 's2'.
 *
 * It returns an integer less than, equal to, or greater than zero, depending on whether
 * 's1' is less than, equal to, or greater than 's2' respectively.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	size_t			result;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			result = str1[i] - str2[i];
			return (result);
		}
		i++;
	}
	return (0);
}
