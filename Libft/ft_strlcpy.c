/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:58:17 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:22:17 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * The ft_strlcpy function copies the string 'src' to the string 'dst', ensuring that the resulting
 * 'dst' string is null-terminated and does not exceed the specified 'dstsize' limit.
 *
 * It returns the total length of the source string.
 *
 * If 'dstsize' is 0, it returns the length of the 'src' string.
 *
 * Note that 'dstsize' should be large enough to accommodate the entire 'src' string
 * plus one additional  character for the null-terminator.
 *
 * If 'dstsize' is less than the length of 'src', the function truncates the copy accordingly.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
