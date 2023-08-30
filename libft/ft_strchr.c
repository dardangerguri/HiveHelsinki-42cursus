/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:49:31 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:04:24 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strchr function searches for the first occurrence of the character 'c' in the string 's'.
 *
 * It returns a pointer to the first occurrence of 'c' in 's', or NULL if 'c' is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	character;

	i = 0;
	str = (char *)s;
	character = (char)c;
	while (str[i] != character && str[i] != '\0')
		i++;
	if (str[i] == character)
		return (str + i);
	else
		return (NULL);
}
