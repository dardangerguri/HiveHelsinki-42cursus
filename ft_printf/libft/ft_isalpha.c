/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:19:27 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/11 22:17:29 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_isalpha function determines whether a given character is an alphabetic letter.
 *
 * This function compares the ASCII values of uppercase letters ('A' to 'Z') and lowercase
 * letters ('a' to 'z') to check if the character 'c' falls within the range of alphabetic letters.
 *
 * It returns a non-zero value if the character is an alphabetic letter, and zero otherwise.
 */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
