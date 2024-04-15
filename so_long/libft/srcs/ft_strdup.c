/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:26:49 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 19:01:42 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
