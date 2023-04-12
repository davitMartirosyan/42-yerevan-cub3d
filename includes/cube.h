/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:11:02 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/12 00:56:29 by tumolabs         ###   ########.fr       */
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
    N player who see's to north 30
    S player who see's to south 35
    E player who see's to east  21
    W player who see's to west  39
*/

#define WIDTH 600
#define HEIGHT 600

typedef struct s_table
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
}   t_table;

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

void    init(t_table **table, t_player **player);
void	free_char_pp(char ***pp);
void    replace_all(char *line);
void    replace_non_integers(char *line, int to);
void    split_function(char **cmap, int i, int j, t_table *table);
void	failure(int err);
void	find_player_position(t_table *table, t_player **player);
int     parser(t_table *table, char *filename);
int     rgb(char *line);
int     textured(char **cmap, t_table *table);
int     floor_ceiling(char **cmap, t_table *table);
int     __set(char **cmap, t_table *table);
int		checked(char *map, t_table *table);
int		height(char **map);
int		width(char **map);
int		head_bottom(char *string);
int		middle(char **map);
int		middle_points(char **map);
int		redefine(t_table *table);
int		convert(t_table *table);
int		board_is_oppend(t_table *table);
char    **copymap(char *filename);
char	*set_map(char *s1, int delimiter, char *s2);
