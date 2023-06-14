/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:21:06 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/14 17:34:59 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_atoi function converts a string representation of an integer to an int value.
 *
 * This is a recreation of the atoi function in C. According to the man page,
 * "The atoi function converts the initial portion of the string pointed to by str to int representation."
 *
 * The function skips leading white spaces and determines the sign of the integer.
 * It then converts the numeric digits until the first non-digit character is encountered.
 *
 * If the conversion is successful and the resulting value is within the range of int, the function
 * returns the converted int value. However, it's important to note that if the value exceeds INT_MAX
 * or is smaller than INT_MIN, the behavior is undefined.
 *
 * To handle possible overflows, this implementation returns -1 if the value exceeds the range of a long int,
 * and returns 0 if it is smaller than a long int. It is important to properly handle and check the return value
 * to handle potential errors and ensure the validity of the converted result.
 */

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58)
	{
		if (result * sign > 2147483647)
			return (-1);
		if (result * sign < -2147483648)
			return (0);
		else
			result = result * 10 + str[i] - '0';
		i++;
	}
	return ((int)result * (int)sign);
}
