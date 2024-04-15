/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:33:31 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:25:57 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The ft_split function splits the string 's' into an array of strings based on the delimiter 'c'.
 *
 * It allocates memory for the array and each individual word using malloc().
 *
 * The resulting array of strings is returned.
 * If the allocation fails, it returns NULL.
 *
 * Note: The function uses memory allocation, so make sure to free the allocated memory using free().
*/

static char	**free_str(char **arr_of_str, int j)
{
	while (j-- >= 0)
		free(arr_of_str[j]);
	free(arr_of_str);
	return (NULL);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	w_number;

	i = 0;
	w_number = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != '\0')
	{
		if (s[i] == c)
		{
			w_number++;
			while (s[i] == c)
				i++;
		}
		if (s[i] == '\0' && s[i - 1] == c)
			return (w_number);
		i++;
		if (s[i] == '\0')
			w_number++;
	}
	return (w_number);
}

static int	word_length(char const *s, char c, int i)
{
	int	length;

	length = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		length++;
		i++;
	}
	return (length);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		w_length;
	char	**arr_of_str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = -1;
	arr_of_str = malloc(sizeof(*arr_of_str) * (word_count(s, c) + 1));
	if (!arr_of_str)
		return (NULL);
	while (++j < word_count(s, c))
	{
		w_length = word_length(s, c, i);
		while (s[i] == c)
			i++;
		if (s[i] != c)
			arr_of_str[j] = ft_substr(s, i, w_length);
		if (arr_of_str[j] == NULL)
			return (free_str(arr_of_str, j));
		i = i + w_length;
	}
	arr_of_str[j] = NULL;
	return (arr_of_str);
}
