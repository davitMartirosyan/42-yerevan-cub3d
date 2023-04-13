/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:11:02 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/13 04:04:27 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "../mlx/mlx.h"
#include <stdlib.h>
#include "../libft/libft.h"
#include "get_next_line.h"
/*
    0 empty space
    1 walls
    N player who see's to north 30 dir {0, 1}
    S player who see's to south 35 dir {0, -1}
    E player who see's to east  21 dir {1, 0}
    W player who see's to west  39 dir {-1, 0}
*/

#define WIDTH 600
#define HEIGHT 600
#define CELL_SIZE 10

typedef struct s_vec2
{
    double	x;
    double	y;
}   t_vec2;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
}	t_player;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_player	*player;
}	t_vars;

typedef struct s_game
{
    int		map_w;
    int		map_h;
    int		no;
    int		so;
    int		we;
    int		ea;
    int		f;
    int		c;
    int		floor;
    int		sky;
    int     cout[4];
    char    *north;
    char    *south;
    char    *east;
    char    *west;
    char    *map;
	int		**mmap;
	t_vars	screen;
	t_player *player;
}   t_game;

void    init(t_game **game, t_player **player);
void	free_char_pp(char ***pp);
void    replace_all(char *line);
int		keyhook(int	keycode, t_game *game);
void	play(t_game *game);
void    replace_non_integers(char *line, int to);
void	draw_map(t_game *game);
void    split_function(char **cmap, int i, int j, t_game *game);
void	failure(int err);
void	find_player_position(t_game *game, t_player *player);
void	find_player_direction(t_game *game, t_player *player);
void	setup(t_game *game, t_player *player);
void	draw_rect(void *mlx, void *win, int x, int y, int aroundcol);
void	draw(t_game *game, int x, int y, int poscol, int aroundcol);
int     parser(t_game *game, char *filename);
int     rgb(char *line);
int     textured(char **cmap, t_game *game);
int     floor_ceiling(char **cmap, t_game *game);
int     __set(char **cmap, t_game *game);
int		checked(char *map, t_game *game);
int		height(char **map);
int		width(char **map);
int		head_bottom(char *string);
int		middle(char **map);
int		middle_points(char **map);
int		redefine(t_game *game);
int		convert(t_game *game);
int		board_is_oppend(t_game *game);
char    **copymap(char *filename);
char	*set_map(char *s1, int delimiter, char *s2);