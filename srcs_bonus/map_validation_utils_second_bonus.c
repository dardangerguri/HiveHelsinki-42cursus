/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils_second_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:59:05 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/10 14:59:58 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	path_validate_y(t_components *comp, int x, int y)
{
	while (comp->map[y][x] != '1' && comp->map[y][x] != 'D')
	{
		if (comp->map[y][x] == 'C')
		{
			comp->map[y][x] = '0';
			comp->c++;
		}
		else if (comp->map[y][x] == 'E')
			comp->exit = 2;
		y++;
	}
	while (y != 0 && comp->map[y][x] != '1' && comp->map[y][x] != 'D')
	{
		if (comp->map[y][x] == 'C')
		{
			comp->map[y][x] = '0';
			comp->c++;
		}
		else if (comp->map[y][x] == 'E' && comp->exit != 2)
			comp->exit = 2;
		y--;
	}
	if (comp->c != comp->collectibles || comp->exit != 2)
		error_message("There is no valid path!\n");
}

void	path_validate_x(t_components *comp, int x, int y)
{
	while (comp->map[y][x] != '1' && comp->map[y][x] != 'D')
	{
		if (comp->map[y][x] == 'C')
		{
			comp->map[y][x] = '0';
			comp->c++;
		}
		else if (comp->map[y][x] == 'E')
			comp->exit = 2;
		x++;
	}
	while (x != 0 && comp->map[y][x] != '1' && comp->map[y][x] != 'D')
	{
		if (comp->map[y][x] == 'C')
		{
			comp->map[y][x] = '0';
			comp->c++;
		}
		else if (comp->map[y][x] == 'E' && comp->exit != 2)
			comp->exit = 2;
		x--;
	}
	if (comp->c != comp->collectibles || comp->exit != 2)
		error_message("There is no valid path!\n");
}

void	path_validate_columns(t_components *comp)
{
	if (comp->columns == 4)
	{
		if ((comp->player_pos.x == 1 && comp->player_pos.y == 1
				&& comp->enemy_pos_x == 1 && comp->enemy_pos_y == 2
				&& comp->map[1][2] == '0') || (comp->player_pos.x == 1
				&& comp->player_pos.y == 1 && comp->enemy_pos_x == 2
				&& comp->enemy_pos_y == 1))
			error_message("There is no valid path!\n");
		if (comp->player_pos.x == 2 && comp->player_pos.y == 2
			&& comp->enemy_pos_x == 1 && comp->enemy_pos_y == 1)
			error_message("There is no valid path!\n");
	}
	if (comp->player_pos.x == 1 && comp->player_pos.y == 1
		&& comp->enemy_pos_x == 2 && comp->enemy_pos_y == 1
		&& ((comp->map[2][2] == '0' || comp->map[1][3] != '0')
		|| comp->map[1][2] != 'D'))
		error_message("There is no valid path!\n");
	else if (comp->player_pos.x == 4 && comp->player_pos.y == 2
		&& comp->enemy_pos_x == 3 && comp->enemy_pos_y == 1)
		error_message("There is no valid path!\n");
}
