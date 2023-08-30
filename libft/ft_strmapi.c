/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:34:01 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:07:43 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_strmapi function applies the function 'f' to each character of the string 's',
 * passing its index as the first argument to 'f'. It creates a new string with the modified characters.
 *
 * It returns a pointer to the newly allocated string.
 *
 * If 's' is NULL, it returns NULL.
 * If memory allocation fails, it returns NULL.
 *
 * Note: The caller is responsible for freeing the memory allocated by ft_strmapi.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		s_length;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_length = ft_strlen(s);
	str = malloc(sizeof(*str) * s_length + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
