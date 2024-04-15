/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:05:13 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 17:48:37 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_memcpy function copies 'n' bytes from the memory area pointed to by 'src' to the memory area
 * pointed to by 'dest'.
 *
 * It returns a pointer to the destination memory area 'dest' after the operation.
 *
 * Note: Both 'src' and 'dest' must be valid memory areas. If either of them is NULL, the function returns NULL.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destination;
	char	*source;

	i = 0;
	destination = (char *)dest;
	source = (char *)src;
	if (source == NULL && destination == NULL)
		return (NULL);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
