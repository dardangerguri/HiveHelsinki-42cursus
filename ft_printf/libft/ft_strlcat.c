/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:31:09 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 13:30:49 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strlcat function appends the string 'src' to the end of the string 'dst', up to a maximum
 * of 'dstsize' characters, ensuring that the resulting string is null-terminated
 *
 * It returns the total length of the concatenated strings.
 *
 * If 'dst' is NULL and 'dstsize' is 0, it returns the length of the 'src' string.
 *
 * It is important to note that 'dstsize' should be large enough to accommodate the combined length
 * of 'dst' and 'src' strings plus one additional character for the null-terminator.
 *
 * If 'dstsize' is less than the length of 'dst', the function truncates the concatenation accordingly.
*/
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
