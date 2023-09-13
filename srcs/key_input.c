/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:35:01 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/11 13:41:43 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ending_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

static void	move_player(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	put_images(game);
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
	move_player(game);
	return (0);
}
