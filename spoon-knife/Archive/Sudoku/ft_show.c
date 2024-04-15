/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple- <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:26:13 by ple-              #+#    #+#             */
/*   Updated: 2022/07/09 18:34:16 by ple-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_putnbr(int nb);

void ft_show(int **argv)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i < 9)
	{
		n = 0;
		while (n < 9)
		{
			ft_putnbr(argv[i][n]);
			n++;
			if (n != 9)
			{
				ft_putchar(' ');
			}
		}
			i++;
			ft_putstr("\n");
	}
}

