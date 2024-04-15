/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:31:09 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 16:25:42 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize < destlen)
		return (srclen + dstsize);
	while (dst[i] != '\0')
		i++;
	while (i < dstsize - 1 && *src != '\0' && dstsize > 0)
	{
		dst[i] = *src++;
		i++;
	}
	dst[i] = '\0';
	return (destlen + srclen);
}
