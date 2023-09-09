/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:05:10 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 19:02:26 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	starting(const char *s1, const char *set)
{
	int		start;
	int		set_length;
	int		f;
	int		x;

	start = 0;
	set_length = ft_strlen(set);
	x = 0;
	while (s1[start] != '\0')
	{
		f = 0;
		while (set[f] != '\0')
		{
			if (set[f] != s1[start] && f == set_length - 1)
				x = 1;
			if (set[f] == s1[start])
				break ;
			f++;
		}
		if (x == 1)
			break ;
		start++;
	}
	return (start);
}

static int	ending(const char *s1, const char *set)
{
	int		end;
	int		set_length;
	int		f;
	int		x;

	end = ft_strlen(s1) - 1;
	set_length = ft_strlen(set);
	x = 0;
	while (end >= 0)
	{
		f = 0;
		while (set[f] != '\0')
		{
			if (set[f] != s1[end] && f == set_length - 1)
				x = 1;
			if (set[f] == s1[end])
				break ;
			f++;
		}
		if (x == 1)
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;
	int		size;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || set[0] == '\0')
		return (ft_strdup(s1));
	start = starting(s1, set);
	end = ending(s1, set);
	size = end - start + 1;
	if (size < 0)
		size = 0;
	result = malloc(sizeof(*result) * size + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s1[start], size + 1);
	return (result);
}
