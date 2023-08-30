/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:25:51 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/11 22:06:27 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_isalnum function determines whether a given character is an alphanumeric character.
 *
 * This function checks if the character 'c' is either a digit ('0' to '9'), an uppercase letter
 * ('A' to 'Z'), or a lowercase letter ('a' to 'z').
 *
 * It returns a non-zero value if the character is an alphanumeric character, and zero otherwise.
 */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
