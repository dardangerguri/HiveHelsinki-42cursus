/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:22:45 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:02:07 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strncmp function compares at most 'n' characters of the strings 's1' and 's2'.
 *
 * It returns an integer less than, equal to, or greater than zero, depending on whether 's1' is less than,
 * equal to, or greater than 's2' respectively.
 *
 * The comparison stops either after 'n' characters have been compared, or if a differing character is found
 * in either 's1' or 's2', or if the end of either string ('\0') is reached.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			result;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
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
