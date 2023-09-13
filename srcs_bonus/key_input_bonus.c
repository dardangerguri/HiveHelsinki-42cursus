/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:35:01 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/11 13:42:30 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ending_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

void	show_moves(t_game *game, int moved)
{
	char	*str;

	mlx_string_put(game->mlx, game->window, 5, 5, 0xffffff, "Moves: ");
	str = ft_itoa(moved);
	mlx_string_put(game->mlx, game->window, 70, 5, 0xffffff, str);
	free(str);
}

static void	move_player(t_game *game, int moved)
{
	mlx_clear_window(game->mlx, game->window);
	put_images(game);
	show_moves(game, moved);
}

int	key(int key_code, t_game *game)
{
	static int	moved;
	int			i;

	i = moved;
	if (key_code == ESC)
		ending_program(game);
	else if (key_code == KEY_UP)
		moved += move_up(game, 0, 0);
	else if (key_code == KEY_DOWN)
		moved += move_down(game, 0, 0);
	else if (key_code == KEY_LEFT)
		moved += move_left(game, 0, 0);
	else if (key_code == KEY_RIGHT)
		moved += move_right(game, 0, 0);
	if (moved != i)
		ft_printf(1, "Moves: %d\n", moved);
	move_player(game, moved);
	return (0);
}
