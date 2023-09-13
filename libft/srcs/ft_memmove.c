/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:44:50 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 19:01:05 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
