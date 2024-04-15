/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:30:54 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/11 22:12:19 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_toupper function converts a lowercase letter to uppercase.
 *
 * This function checks if the character 'c' is a lowercase letter ('a' to 'z').
 * If it is, it converts it to uppercase by subtracting 32 from its ASCII value,
 * effectively transforming it to the corresponding uppercase letter.
 *
 * It returns the uppercase equivalent of the character 'c' if it is a lowercase letter,
 * or the same character if it is already uppercase or not a lowercase letter.
 */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
