/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:12:50 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/05 18:36:30 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	up_down_enemy(t_game *game, int x, int y)
{
	x = game->components.enemy_pos_x;
	y = game->components.enemy_pos_y;
	if ((game->map_copy[y][x + 1] == '1' || game->map_copy[y][x + 1] == 'E'
		|| game->map_copy[y][x + 1] == 'C') && game->flag_enemy == 0)
		game->flag_enemy = 1;
	else if ((game->map_copy[y][x - 1] == '1' || game->map_copy[y][x - 1] == 'E'
		|| game->map_copy[y][x - 1] == 'C') && game->flag_enemy == 1)
		game->flag_enemy = 0;
	else if ((game->map_copy[y][x + 1] != '1' || game->map_copy[y][x + 1] != 'E'
		|| game->map_copy[y][x + 1] != 'C') && game->flag_enemy == 0)
	{
		if (game->map_copy[y][x] != 'P')
			game->map_copy[y][x] = '0';
		game->map_copy[y][x + 1] = 'D';
		game->components.enemy_pos_x += 1;
	}
	else if ((game->map_copy[y][x - 1] != '1' || game->map_copy[y][x - 1] != 'E'
		|| game->map_copy[y][x - 1] != 'C') && game->flag_enemy == 1)
	{
		if (game->map_copy[y][x] != 'P')
			game->map_copy[y][x] = '0';
		game->map_copy[y][x - 1] = 'D';
		game->components.enemy_pos_x -= 1;
	}
}

static void	left_right_enemy(t_game *game, int x, int y)
{
	x = game->components.enemy_pos_x;
	y = game->components.enemy_pos_y;
	if ((game->map_copy[y + 1][x] == '1' || game->map_copy[y + 1][x] == 'E'
		|| game->map_copy[y + 1][x] == 'C') && game->flag_enemy2 == 0)
		game->flag_enemy2 = 1;
	else if ((game->map_copy[y - 1][x] == '1' || game->map_copy[y - 1][x] == 'E'
		|| game->map_copy[y - 1][x] == 'C') && game->flag_enemy2 == 1)
		game->flag_enemy2 = 0;
	else if ((game->map_copy[y + 1][x] != '1' || game->map_copy[y + 1][x] != 'E'
		|| game->map_copy[y + 1][x] != 'C') && game->flag_enemy2 == 0)
	{
		if (game->map_copy[y][x] != 'P')
			game->map_copy[y][x] = '0';
		game->map_copy[y + 1][x] = 'D';
		game->components.enemy_pos_y += 1;
	}
	else if ((game->map_copy[y - 1][x] != '1' || game->map_copy[y - 1][x] != 'E'
		|| game->map_copy[y - 1][x] != 'C') && game->flag_enemy2 == 1)
	{
		if (game->map_copy[y][x] != 'P')
			game->map_copy[y][x] = '0';
		game->map_copy[y - 1][x] = 'D';
		game->components.enemy_pos_y -= 1;
	}
}

static void	eaten_by_enemy(t_game *game, int x, int y)
{
	if (game->map_copy[y][x] == game->map_copy[game->components.enemy_pos_y] \
		[game->components.enemy_pos_x])
	{
		game->map_copy[y][x] = 'D';
		game->player = 0;
	}
}

static void	enemy_patrol(t_game *game, int move_direction)
{
	if (move_direction == 1 || move_direction == 2)
		up_down_enemy(game, 0, 0);
	else if (move_direction == 3 || move_direction == 4)
		left_right_enemy(game, 0, 0);
}

void	enemy(t_game *game, int direction, int x, int y)
{
	if (game->components.enemy == 1)
	{
		enemy_patrol(game, direction);
		eaten_by_enemy(game, x, y);
	}
}
