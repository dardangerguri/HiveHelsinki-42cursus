/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:53:30 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/10 15:00:41 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	form_checker(t_map *map, t_components *components)
{
	if (components->rows < 3 || components->columns < 3)
		error_message("It is not a proper map!\n");
	while (map != NULL)
	{
		if (ft_strlen(map->line) != components->columns + 1)
			error_message("Map is not rectengular!\n");
		map = map->next;
	}
}

static void	wall_checker(t_map *map, t_components *components)
{
	char	*line;
	size_t	i;

	line = map->line;
	i = -1;
	while (++i < components->columns)
		if (line[i] != '1')
			error_message("Map is not sorrounded by walls!\n");
	while (map->next->next != NULL)
	{
		line = map->next->line;
		if (line[0] != '1' || line[components->columns - 1] != '1')
			error_message("Map is not sorrounded by walls!\n");
		map = map->next;
	}
	line = map->next->line;
	i = -1;
	while (++i < components->columns)
		if (line[i] != '1')
			error_message("Map is not sorrounded by walls!\n");
}

static void	content_checker(t_components *comp, int y, size_t x)
{
	y = -1;
	while (++y < comp->rows)
	{
		x = 0;
		while (++x < comp->columns - 1)
		{
			if (comp->map[y][x] == 'C')
				comp->collectibles++;
			else if (comp->map[y][x] == 'P')
			{
				comp->player++;
				player_pos(comp, y, x);
			}
			else if (comp->map[y][x] == 'E')
				comp->exit++;
			else if (comp->map[y][x] == 'D')
			{
				comp->enemy++;
				player_pos(comp, y, x);
			}
			else if (comp->map[y][x] != '1' && comp->map[y][x] != '0')
				error_message("Map has some unknown content!\n");
		}
	}
}

static void	path_checker(t_components *comp)
{
	int	y;
	int	x;

	y = comp->player_pos.y;
	x = comp->player_pos.x;
	if (comp->columns == 3)
		path_validate_y(comp, x, y);
	if (comp->rows == 3)
		path_validate_x(comp, x, y);
	if (comp->rows == 4 && comp->enemy == 1)
		path_validate_columns(comp);
	if (flood_fill(comp, comp->player_pos, comp->map) == 0)
		error_message("There is no valid path!\n");
}

int	validate_map(t_map *map, t_components *components)
{
	components->rows = nbr_lines(map);
	components->columns = ft_strlen(map->line) - 1;
	components->map = create_array(map, components->rows);
	form_checker(map, components);
	wall_checker(map, components);
	content_checker(components, -1, 0);
	if (components->player != 1 || components->exit != 1)
		error_message("It is not the correct number of players or exits!\n");
	if (components->enemy > 1)
		error_message("There is more than one enemy!\n");
	if (components->collectibles < 1)
		error_message("There are no collectibles!\n");
	path_checker(components);
	return (0);
}
