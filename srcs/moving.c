/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:34:20 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/05 18:42:26 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_collectibles_exit(t_game *game, int x, int y)
{
	if (game->map_copy[y][x] == 'C')
		game->components.collectibles--;
	else if (game->map_copy[y][x] == 'E')
		game->components.exit = 1;
}

int	move_up(t_game *game, int x, int y)
{
	y = game->components.player_pos.y - 1;
	x = game->components.player_pos.x;
	if (game->map_copy[y][x] == '1')
		return (0);
	else if (game->components.exit == 1)
	{
		if (game->map_copy[y][x] == 'C')
			game->components.collectibles--;
		game->map_copy[y][x] = 'P';
		game->map_copy [y + 1][x] = 'E';
		game->components.exit = 2;
		game->components.player_pos.y = y;
	}
	else
	{
		check_collectibles_exit(game, x, y);
		game->map_copy[y][x] = 'P';
		game->map_copy [y + 1][x] = '0';
		game->components.player_pos.y = y;
	}
	return (1);
}

int	move_down(t_game *game, int x, int y)
{
	y = game->components.player_pos.y + 1;
	x = game->components.player_pos.x;
	if (game->map_copy[y][x] == '1')
		return (0);
	else if (game->components.exit == 1)
	{
		if (game->map_copy[y][x] == 'C')
			game->components.collectibles--;
		game->map_copy[y][x] = 'P';
		game->map_copy [y - 1][x] = 'E';
		game->components.exit = 2;
		game->components.player_pos.y = y;
	}
	else
	{
		check_collectibles_exit(game, x, y);
		game->map_copy[y][x] = 'P';
		game->map_copy [y - 1][x] = '0';
		game->components.player_pos.y = y;
	}
	return (1);
}

int	move_left(t_game *game, int x, int y)
{
	y = game->components.player_pos.y;
	x = game->components.player_pos.x - 1;
	if (game->map_copy[y][x] == '1')
		return (0);
	else if (game->components.exit == 1)
	{
		if (game->map_copy[y][x] == 'C')
			game->components.collectibles--;
		game->map_copy[y][x] = 'P';
		game->map_copy [y][x + 1] = 'E';
		game->components.exit = 2;
		game->components.player_pos.x = x;
	}
	else
	{
		check_collectibles_exit(game, x, y);
		game->map_copy[y][x] = 'P';
		game->map_copy [y][x + 1] = '0';
		game->components.player_pos.x = x;
	}
	return (1);
}

int	move_right(t_game *game, int x, int y)
{
	y = game->components.player_pos.y;
	x = game->components.player_pos.x + 1;
	if (game->map_copy[y][x] == '1')
		return (0);
	else if (game->components.exit == 1)
	{
		if (game->map_copy[y][x] == 'C')
			game->components.collectibles--;
		game->map_copy[y][x] = 'P';
		game->map_copy [y][x - 1] = 'E';
		game->components.exit = 2;
		game->components.player_pos.x = x;
	}
	else
	{
		check_collectibles_exit(game, x, y);
		game->map_copy[y][x] = 'P';
		game->map_copy [y][x - 1] = '0';
		game->components.player_pos.x = x;
	}
	return (1);
}
