/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:13:50 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/11 22:11:08 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_tolower function converts an uppercase letter to lowercase.
 *
 * This function checks if the character 'c' is an uppercase letter ('A' to 'Z').
 * If it is, it converts it to lowercase by adding 32 to its ASCII value, effectively
 * transforming it to the corresponding lowercase letter.
 *
 * It returns the lowercase equivalent of the character 'c' if it is an uppercase letter,
 * or the same character if it is already lowercase or not an uppercase letter.
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
