/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 08:43:23 by dgerguri          #+#    #+#             */
/*   Updated: 2022/07/11 10:10:25 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	compare(char *s1, char *s2)
{
	int	index;

	index = 0;	
	while (s1[index] != '\0' && s2[index] != '\0')
	{ 
		if (s2[index] == '*')
			s2[index] = s1[index];

		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
			index++;
	}	
	if (s1[index] == '\0')
		return ('\0' - s2[index]);
	if (s2[index] == '\0')
		return (s1[index]);
	return (0);
}

int	match(char *s1, char *s2)
{
	if (compare(s1, s2) == 0)
		return (1);
	else
		return (0);
}
