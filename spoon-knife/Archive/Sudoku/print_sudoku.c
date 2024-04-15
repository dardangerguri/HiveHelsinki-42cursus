/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple- <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:17:21 by ple-              #+#    #+#             */
/*   Updated: 2022/07/10 08:33:54 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include<unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_putnbr(int nb);

void	ft_show(int **argv);

int	**change_dot(char **argv)
{
	int	**table;
	int	i;
	int	n;

	n = 0;
	i = 1;
	table = malloc(sizeof(int *) * 9);
	while (i <= 9)
	{
		table[i-1] = malloc(sizeof(int) * 9);
		n = 0;
		while (n <= 9)
		{
			if (argv[i][n] == '.')
			{
				argv[i][n] = '0';

			}
			table[i-1][n] = argv[i][n] - 48;
			n++;
		}
		i++;
	}
	table[i-1] = 0;
	return (table);
}

int	main(int argc, char **argv)
{
	int	**sudoku_table;

	if ((argc - 1) != 9)
	{
		ft_putstr("Error\n");
		return (0);
	}
	sudoku_table = change_dot(argv);
	ft_show(sudoku_table);
	return (0);
}

