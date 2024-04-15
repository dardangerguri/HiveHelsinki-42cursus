/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_first_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:03:58 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/08 22:01:53 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	nbr_lines(t_map *map)
{
	int	size;

	size = 0;
	if (map == NULL)
		return (0);
	while (map != NULL)
	{
		map = map->next;
		size++;
	}
	return (size);
}

char	**create_array(t_map *map, int rows)
{
	char	**array;
	int		i;

	array = malloc(sizeof(*array) * (rows + 1));
	if (array == NULL)
		error_message("Allocation has failed!\n");
	i = 0;
	while (i < rows)
	{
		array[i] = ft_strdup(map->line);
		if (array[i] == NULL)
		{
			while (i > 0)
			{
				free(array[--i]);
			}
			free(array);
			error_message("Allocation has failed!\n");
		}
		map = map->next;
		i++;
	}
	array[rows] = NULL;
	return (array);
}

void	player_pos(t_components *components, int y, int x)
{
	if (components->map[y][x] == 'P')
	{
		components->player_pos.y = y;
		components->player_pos.x = x;
	}
	else if (components->map[y][x] == 'D')
	{
		components->enemy_pos_y = y;
		components->enemy_pos_x = x;
	}
}

int	flood_fill(t_components *components, t_vector position, char **map)
{
	if (map[position.y][position.x] == '1')
		return (0);
	else if (map[position.y][position.x] == 'E')
		components->exit = 2;
	else if (map[position.y][position.x] == 'C')
		components->c++;
	map[position.y][position.x] = '1';
	flood_fill(components, (t_vector){position.y, position.x + 1}, map);
	flood_fill(components, (t_vector){position.y, position.x - 1}, map);
	flood_fill(components, (t_vector){position.y + 1, position.x}, map);
	flood_fill(components, (t_vector){position.y - 1, position.x}, map);
	if (components->c == components->collectibles && components->exit == 2)
		return (1);
	return (0);
}
