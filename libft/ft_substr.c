/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:27:09 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:07:03 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_substr function creates a new substring from the string 's', starting at index 'start'
 * and with a maximum length of 'len'.
 * It returns a pointer to the newly allocated substring.
 *
 * If 's' is NULL, it returns NULL.
 * If 'start' is greater than the length of 's', it returns an empty string.
 * If 'len' exceeds the length of the remaining characters in 's', it adjusts 'len' to the maximum possible length.
 * If memory allocation fails, it returns NULL.
 *
 * Note: The caller is responsible for freeing the memory allocated by ft_substr.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*sub_str;

	i = 0;
	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	if (start == 0 || start > length)
	{
		if (start > length)
			len = 0;
		if (len > length)
			len = length;
	}
	sub_str = malloc(sizeof(char) * (len + 1));
	if (sub_str == NULL)
		return (NULL);
	while (i < len && start < length)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
