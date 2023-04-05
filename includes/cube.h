/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:11:02 by tumolabs          #+#    #+#             */
/*   Updated: 2023/04/06 02:02:21 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <mlx.h>
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
    char    *north;
    char    *south;
    char    *east;
    char    *west;
}   t_table;


void    init(t_table **table);
int     failure(int err);
int     parser(t_table *table, char *filename);
void    texture_line(char *line, t_table *table);