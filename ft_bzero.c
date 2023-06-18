/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:43:49 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 17:41:42 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_bzero function sets the first 'n' bytes of the memory area pointed to by 's' to zero.
 *
 * This function is used to clear a block of memory by setting each byte to zero.
 * It takes a pointer 's' to the memory area and the number of bytes 'n' to be set to zero.
 * It iterates over the memory area, setting each byte to zero until 'n' becomes zero.
 *
 * After the operation, the memory area pointed to by 's' will contain all zeros.
*/

void	ft_bzero(void *s, size_t n)
{
	char	*dest;

	dest = s;
	while (n > 0)
	{
		*dest = 0;
		dest++;
		n--;
	}
}
