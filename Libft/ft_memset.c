/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:51:57 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 17:47:26 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_memset function fills the first 'len' bytes of the memory area pointed to by 'b'
 * with the constant byte 'c'.
 *
 * It returns a pointer to the memory area 'b' after the operation.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*destination;
	unsigned char	character;

	destination = (unsigned char *)b;
	character = (unsigned char)c;
	while (len > 0)
	{
		*destination = character;
		destination++;
		len--;
	}
	return (b);
}
