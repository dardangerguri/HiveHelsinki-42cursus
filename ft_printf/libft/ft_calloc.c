/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:25:57 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 17:43:22 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_calloc function allocates memory for an array of 'count' elements, each of size 'size',
 * and initializes the allocated memory to zero. It returns a pointer to the allocated memory.
 *
 * If either 'count' or 'size' is zero, a single byte of memory is allocated and initialized.
 *
 * If an integer overflow occurs during the allocation, NULL is returned.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (count * size / size != count || count * size / count != size)
		return (NULL);
	s = malloc (size * count);
	if (s == NULL)
		return (NULL);
	ft_bzero (s, (size * count));
	return (s);
}
