/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:09:29 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/05 18:36:38 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	game_initialization(t_map *map, t_components components)
{
	t_game	game;

	game.components = components;
	game.flag_enemy = 0;
	game.flag_enemy2 = 0;
	game.map_copy = create_array(map, game.components.rows);
	if (game.components.columns * SIZE > 1920)
		game.width = 1920;
	else
		game.width = game.components.columns * SIZE;
	if (game.components.rows * SIZE > 1056)
		game.height = 1056;
	else
		game.height = game.components.rows * SIZE;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.width, game.height, "so_long");
	sprite_initialization(&game);
	put_images(&game);
	show_moves(&game, 0);
	mlx_hook(game.window, 17, 0, ending_program, &game);
	mlx_key_hook(game.window, key, &game);
	mlx_loop(game.mlx);
}

int	main(int argc, char **argv)
{
	t_map			*map;
	t_components	components;

	ft_bzero(&components, sizeof(t_components));
	file_validation(argc, argv);
	map = map_read(argv[1]);
	if (map == NULL)
		error_message("Can't read the map");
	validate_map(map, &components);
	game_initialization(map, components);
	return (0);
}
