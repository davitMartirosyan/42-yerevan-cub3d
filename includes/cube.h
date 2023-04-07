/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:11:02 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/07 15:12:19 by dmartiro         ###   ########.fr       */
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
    N player who see's to north 8
    S player who see's to south 2
    E player who see's to east  6
    W player who see's to west  4
*/

#define WIDTH 600
#define HEIGHT 600

typedef struct s_table
{
    int map_w;
    int map_h;
    int no;
    int so;
    int we;
    int ea;
    int f;
    int c;
    int floor;
    int sky;
    int     cout[4];
    char    *north;
    char    *south;
    char    *east;
    char    *west;
    char    *map;
}   t_table;

typedef struct s_vec3
{
    float   x;
    float   y;
    float   z;
}   t_vec3;



void    init(t_table **table);
void	free_char_pp(char ***pp);
void    replace_all(char *line);
void    replace_non_integers(char *line, int to);
void    split_function(char **cmap, int i, int j, t_table *table);
int     parser(t_table *table, char *filename);
int     rgb(char *line);
int     failure(int err);
int     textured(char **cmap, t_table *table);
int     floor_ceiling(char **cmap, t_table *table);
char    **copymap(char *filename);
char	*set_map(char *s1, int delimiter, char *s2);
int     __set(char **cmap, t_table *table);
