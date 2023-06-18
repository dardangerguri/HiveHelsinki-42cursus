/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:26:49 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:03:52 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strdup function duplicates the string 's1' by allocating memory for a new string and copying
 * the contents of 's1' into it. It returns a pointer to the newly allocated string.
 *
 * If memory allocation fails, it returns NULL.
 *
 * Note: The caller is responsible for freeing the memory allocated by ft_strdup.
*/

char	*ft_strdup(const char *s1)
{
	int		i;
	int		length;
	char	*s;

	i = 0;
	length = ft_strlen(s1);
	s = malloc(sizeof(*s) * (length + 1));
	if (s == NULL)
		return (NULL);
	while (i < length)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
