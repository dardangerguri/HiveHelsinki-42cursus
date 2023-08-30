/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:16:10 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/11 22:10:12 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_isprint function determines whether a given character is a printable character.
 *
 * This function checks if the character 'c' falls within the range of printable ASCII characters,
 * which is from 32 to 126 (inclusive). Printable characters include all visible characters except
 * for the space character (ASCII 32).
 *
 * It returns a non-zero value if the character is a printable character, and zero otherwise.
 */

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	else
		return (0);
}
