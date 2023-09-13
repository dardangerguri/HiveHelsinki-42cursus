/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:22:55 by dgerguri          #+#    #+#             */
/*   Updated: 2023/09/13 16:56:12 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

static void	assign_image(t_game *game, char character, int x, int y)
{
	if (game->components.collectibles == 0 && game->components.exit == 1)
	{
		ft_printf(1, "Congrats, you are done!\n");
		exit (0);
	}
	if (character == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, x, y);
	else if (character == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player, x, y);
	else if (character == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, x, y);
	else if (character == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->c, x, y);
}

static void	get_top_left_y_and_x(t_game *g, int *y, int *x, int type)
{
	if (type == 1)
	{
		*y = 0;
		if (g->components.player_pos.y - 33 / 2 > 0)
		{
			if (g->components.rows - g->components.player_pos.y > 32 / 2)
				*y = g->components.player_pos.y - 33 / 2;
			else
				*y = g->components.rows - 33;
		}
	}
	else if (type == 2)
	{
		if (g->components.player_pos.x - 60 / 2 > 0)
		{
			if (g->components.columns - g->components.player_pos.x > 60 / 2)
				*x = g->components.player_pos.x - 60 / 2;
			else
			{
				*x = g->components.columns - 60;
				if (*x < 0)
					*x = 0;
			}
		}
	}
}

static int	put_images_long(t_game *g, int row, int column, int x)
{
	int	y;

	get_top_left_y_and_x(g, &y, 0, 1);
	while (y < g->components.rows)
	{
		column = 0;
		x = 0;
		get_top_left_y_and_x(g, 0, &x, 2);
		while ((size_t)x < g->components.columns)
		{
			assign_image(g, g->map_copy[y][x],
				column * SIZE, row * SIZE);
			column++;
			x++;
		}
		row++;
		y++;
	}
	return (1);
}

int	put_images(t_game *game)
{
	int		row;
	size_t	column;

	row = 0;
	column = 0;
	if ((game->components.rows > 33 || game->components.columns > 60)
		&& (game->components.player_pos.y > 33 / 2
			|| game->components.player_pos.x > 60 / 2))
		return (put_images_long(game, row, column, 0));
	while (row < game->components.rows)
	{
		column = 0;
		while (column < game->components.columns)
		{
			assign_image(game, game->map_copy[row][column],
				column * SIZE, row * SIZE);
			column++;
		}
		row++;
	}
	return (1);
}

void	sprite_initialization(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, "sprites/P.xpm", &x, &y);
	game->c = mlx_xpm_file_to_image(game->mlx, "sprites/C.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &x, &y);
}
