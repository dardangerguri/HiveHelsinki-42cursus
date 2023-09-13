/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:42:06 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/03 16:16:29 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_map	*get_last_node(t_map *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

static t_map	*new_stack_node(char *line)
{
	t_map	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->line = line;
	node->next = NULL;
	return (node);
}

static void	add_line_end(t_map **list, t_map *new_line)
{
	t_map	*temporary;

	if (list == NULL)
		ft_error(NULL, NULL);
	if (new_line == NULL)
		ft_error(list, NULL);
	if (*list == NULL)
		*list = new_line;
	else
	{
		temporary = get_last_node(*list);
		temporary->next = new_line;
	}
}

static void	fix_newline_files(t_map *map)
{
	t_map	*temp;
	char	*line;
	int		i;

	i = 0;
	if (map != NULL)
	{
		temp = get_last_node(map);
		line = temp->line;
		while (line[i] != '\0')
			i++;
		if (line[i - 1] != '\n')
		{
			line[i] = '\n';
			line[i + 1] = '\0';
		}
	}
}

t_map	*map_read(char *argv)
{
	t_map	*map;
	char	*line;
	int		fd;

	map = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_message("Cannot open the file!\n");
	line = get_next_line(fd);
	if (line == NULL)
		error_message("Read failed!\n");
	add_line_end(&map, new_stack_node(line));
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		add_line_end(&map, new_stack_node(line));
	}
	close(fd);
	fix_newline_files(map);
	return (map);
}
