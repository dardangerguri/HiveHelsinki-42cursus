/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:42:46 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 19:02:18 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	f;
	char	*str;
	char	*str_needle;

	i = 0;
	str = (char *)haystack;
	str_needle = (char *)needle;
	if (str == NULL && len == 0)
		return (0);
	if (*str_needle == '\0')
		return (str);
	while (str[i] != '\0' && i < len)
	{
		f = 0;
		while (str[i + f] == str_needle[f] && (i + f) < len)
		{
			if (str_needle[f + 1] == '\0')
				return (&str[i]);
			f++;
		}
		i++;
	}
	return (NULL);
}
