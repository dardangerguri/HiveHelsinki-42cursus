/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:22:41 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:08:58 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strrchr function searches for the last occurrence of the character 'c' in the string 's'.

 * It returns a pointer to the last occurrence of 'c' in 's', or NULL if 'c' is not found.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	character;
	int		i;

	str = (char *)s;
	character = (char)c;
	i = ft_strlen(str);
	while (str[i] != character && i != 0)
		i--;
	if (s[i] == character)
		return (str + i);
	else
		return (NULL);
}
