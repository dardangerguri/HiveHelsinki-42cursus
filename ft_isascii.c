/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:23:57 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/11 22:08:46 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_isascii function determines whether a given character is a valid ASCII character.
 *
 * This function checks if the character 'c' falls within the range of valid ASCII characters,
 * which is from 0 to 127 (inclusive).
 *
 * It returns a non-zero value if the character is a valid ASCII character, and zero otherwise.
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
