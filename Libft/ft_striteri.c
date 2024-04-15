/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:47:58 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:03:40 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_striteri function applies the function 'f' to each character of the string 's',
 * passing its index as the first argument to 'f'.
 *
 * If 's' or 'f' is NULL, the function does nothing and returns.
 *
 * It iterates over the characters of 's' until the end ('\0') is reached, and for each character,
 * it calls the function 'f' with the index and a pointer to the character.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (s == '\0' || f == '\0')
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
