/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:52:37 by dgerguri          #+#    #+#             */
/*   Updated: 2022/07/01 21:17:57 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>


int ft_putchar()
{
return (0);
}

void	ft_ft(int *nbr)
{

	*nbr = 42;	

}
	
int 	main()
{
	int number = 2;
	int *pointer;
	pointer = &number;
	printf("the number is %d", number);
	ft_ft(pointer);
	printf("the number is %d", number);
	return (0);
}

