/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple- <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:25:54 by ple-              #+#    #+#             */
/*   Updated: 2022/07/09 18:24:27 by ple-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	long long	number;

	number = nb;
	if (number < 0)
	{
		number = -nb;
		ft_putchar('-');
	}
	if (number <= 9)
	{
		ft_putchar(number + 48);
	}
	if (number >= 10)
	{	
		ft_putnbr(number / 10);
		ft_putchar((number % 10) + 48);
	}
}
