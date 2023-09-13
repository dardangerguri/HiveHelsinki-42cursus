/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:05 by dgerguri          #+#    #+#             */
/*   Updated: 2023/05/05 19:23:33 by dgerguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

# ifndef SIZE
#  define SIZE 32
# endif

typedef struct s_vector
{
	int	y;
	int	x;
}	t_vector;

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}				t_map;

typedef struct s_components
{
	size_t		columns;
	int			rows;
	int			collectibles;
	int			c;
	int			player;
	int			exit;
	char		**map;
	t_vector	player_pos;
}			t_components;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				width;
	int				height;
	void			*wall;
	void			*player;
	void			*c;
	void			*exit;
	char			**map_copy;
	t_components	components;
}	t_game;

enum	e_key_code
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	ESC = 53
};

/* file validation */
void	file_validation(int argc, char **argv);

/* read and save */
t_map	*map_read(char *argv);

/* error */
void	ft_error(t_map **list, t_map *line);
void	error_message(char *message);
void	free_map(t_map **list);

/* map validation */
int		validate_map(t_map *map, t_components *components);

/* map validation utils */
int		flood_fill(t_components *components, t_vector position, char **map);
int		nbr_lines(t_map *map);
void	player_pos(t_components *components, int y, int x);
char	**create_array(t_map *map, int rows);

/* game initialization */
void	sprite_initialization(t_game *game);
int		put_images(t_game *game);

/* key_input */
int		key(int key_code, t_game *game);
int		ending_program(t_game *game);

/* moving */
int		move_up(t_game *game, int x, int y);
int		move_down(t_game *game, int x, int y);
int		move_left(t_game *game, int x, int y);
int		move_right(t_game *game, int x, int y);

#endif
