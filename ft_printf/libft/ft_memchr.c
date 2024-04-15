/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:07:14 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 13:30:29 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_memchr function searches for the first occurrence of the byte 'c' in the first 'n' bytes
 * of the memory area pointed to by 's'.
 *
 * It returns a pointer to the byte found, or NULL if the byte is not found within the given memory area.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	character;

	i = 0;
	str = (unsigned char *)s;
	character = (unsigned char)c;
	while (str[i] != character && str[i] != '\0' && i < n)
		i++;
	while (i < n)
	{
		if (str[i] == character)
			return (str + i);
		i++;
	}
	return (NULL);
}
