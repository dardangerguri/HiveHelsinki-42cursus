/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:42:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:08:12 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strnstr function locates the first occurrence of the substring 'needle' in the string 'haystack'
 * within the first 'len' characters. It returns a pointer to the located substring within 'haystack',
 * or NULL if the substring is not found.
 *
 * If 'haystack' or 'needle' is NULL, it returns NULL.
 * If 'needle' is an empty string, it returns 'haystack'.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	f;
	char	*str;
	char	*str_needle;

	i = 0;
	str = (char *)haystack;
	str_needle = (char *)needle;
	if (str == NULL && len == 0)
		return (0);
	if (*str_needle == '\0')
		return (str);
	while (str[i] != '\0' && i < len)
	{
		f = 0;
		while (str[i + f] == str_needle[f] && (i + f) < len)
		{
			if (str_needle[f + 1] == '\0')
				return (&str[i]);
			f++;
		}
		i++;
	}
	return (NULL);
}
