/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:26:08 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/11 22:09:27 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_isdigit function determines whether a given character is a digit.
 *
 * This function checks if the character 'c' falls within the range of digit characters,
 * which is from '0' to '9'.
 *
 * It returns a non-zero value if the character is a digit, and zero otherwise.
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
