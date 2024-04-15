/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:42:38 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/09 22:02:12 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static int	word_length(char const *s, char const c, int i)
{
	int	flag;
	int	x;
	int	quote;

	flag = 0;
	x = 0;
	quote = 0;
	while (s[i] == ' ')
	{
		i++;
		x = i;
	}
	if (s[i] != '\0' && s[i] == '\'')
	{
		flag = 1;
		i++;
		quote = 2;
	}
	while (s[i] != '\0' && flag == 1 && s[i] != '\'')
		i++;
	while (s[i] != '\0' && s[i] != c && s[i] != '\'')
		i++;
	if (flag == 1)
		i++;
	return (i - x - quote);
}

static int	word_count_quotes(char const *s, char const c, int w_number)
{
	int	flag;
	int	x;
	int	i;

	flag = 0;
	x = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c || flag != 0)
			x = 0;
		if (s[i] == '\'' && flag == 0)
		{
			flag = 1;
			w_number++;
		}
		else if (s[i] == '\'' && flag == 1)
			flag = 0;
		if (s[i] != c && s[i] != '\'' && flag == 0 && x == 0)
		{
			w_number++;
			x = 1;
		}
	}
	return (w_number);
}

static char	**split_pipex(char const *s, char c, int i, int j)
{
	char	**arr_of_str;
	int		w_length;

	arr_of_str = malloc(sizeof(*arr_of_str) * (word_count_quotes(s, c, 0)) + 1);
	if (arr_of_str == NULL)
		return (NULL);
	while (++j < word_count_quotes(s, c, 0))
	{
		w_length = word_length(s, c, i);
		while (s[i] == c)
			i++;
		if (s[i] == '\'')
			i++;
		arr_of_str[j] = ft_substr(s, i, w_length);
		if (arr_of_str[j] == NULL)
		{
			while (j-- >= 0)
				free(arr_of_str[j]);
			free(arr_of_str);
			return (NULL);
		}
		i = i + w_length;
	}
	arr_of_str[j] = NULL;
	return (arr_of_str);
}

static int	count_quotes(const char *s, char c)
{
	int	nbr_quotes;
	int	i;

	nbr_quotes = 0;
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			nbr_quotes++;
		i++;
	}
	return (nbr_quotes);
}

char	**ft_split_pipex(char const *s, char c)
{
	int		nbr_quotes;
	char	**arr_of_str;

	arr_of_str = NULL;
	if (s == NULL)
		return (NULL);
	nbr_quotes = count_quotes(s, '\'');
	if (nbr_quotes == 0 || nbr_quotes % 2 != 0)
		return (ft_split(s, ' '));
	else
	{
		arr_of_str = split_pipex(s, c, 0, -1);
		if (arr_of_str == NULL)
			return (NULL);
	}
	return (arr_of_str);
}
