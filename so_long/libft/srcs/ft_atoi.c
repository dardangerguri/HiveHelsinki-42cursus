/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:21:06 by dgerguri          #+#    #+#             */
/*   Updated: 2023/06/18 18:59:35 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
