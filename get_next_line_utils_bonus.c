/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:47:08 by dgerguri          #+#    #+#             */
/*   Updated: 2022/12/05 14:51:24 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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
