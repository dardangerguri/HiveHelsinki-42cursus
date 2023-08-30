/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:44:50 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 17:49:16 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_memmove function copies 'len' bytes from the memory area pointed to by 'src' to the memory area
 * pointed to by 'dst'.
 *
 * It returns a pointer to the destination memory area 'dst' after the operation.
 *
 * Note: Both 'src' and 'dst' must be valid memory areas. If either of them is NULL, the function returns NULL.
 * If 'dst' and 'src' overlap, the copy is performed in a non-destructive manner.
 */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (destination == NULL && source == NULL)
		return (NULL);
	if (destination > source)
	{
		while (len > 0 && len--)
			destination[len] = source[len];
	}
	while (i < len)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
