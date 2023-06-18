/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:21:37 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:05:03 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strjoin function concatenates two strings 's1' and 's2' into a newly allocated string.
 * It returns a pointer to the concatenated string.
 *
 * If either 's1' or 's2' is NULL, it returns NULL.
 * If memory allocation fails, it returns NULL.
 *
 * Note: The caller is responsible for freeing the memory allocated by ft_strjoin.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		i_s2;
	char	*str;

	i = 0;
	i_s2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i_s2] != '\0')
	{
		str[i] = s2[i_s2];
		i++;
		i_s2++;
	}
	str[i] = '\0';
	return (str);
}
