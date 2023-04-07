/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 01:33:06 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/06 12:49:47 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


int parser(t_table *table, char *filename)
{
    char    **cmap;

    cmap = copymap(filename);
    if (!textured(cmap, table))
        return (0);
    return (1);
}

int textured(char **cmap, t_table *table)
{
    int i;
    int j;

    i = 0;
    while (cmap[i])
    {
        j = 0;
        while (cmap[i][j])
        {
            if (ft_isspace(cmap[i][j]))
            {
                j++;
                continue;
            }
            else if (ft_toupper(cmap[i][j]) == 'N' && ft_toupper(cmap[i][j + 1]) == 'O')
            {
                table->north = ft_strjoin(table->north, cmap[i] + j + 2);
                replace_all(cmap[i]);
            }
            else if (ft_toupper(cmap[i][j]) == 'S' && ft_toupper(cmap[i][j + 1]) == 'O')
            {
                table->south = ft_strjoin(table->south, cmap[i] + j + 2);
                replace_all(cmap[i]);
            }
            else if (ft_toupper(cmap[i][j]) == 'W' && ft_toupper(cmap[i][j + 1]) == 'E')
            {
                table->west = ft_strjoin(table->west, cmap[i] + j + 2);
                replace_all(cmap[i]);
            }
            else if (ft_toupper(cmap[i][j]) == 'E' && ft_toupper(cmap[i][j + 1]) == 'A')
            {
                table->east = ft_strjoin(table->east, cmap[i] + j + 2);
                replace_all(cmap[i]);
            }
            j++;
        }
        i++;
    }
    return (1);
}

void    replace_all(char *line)
{
    int i;

    i = -1;
    while (line[++i])
        line[i] = '9';
}

char    **copymap(char *filename)
{
    int     fd;
    char    *cpmap;
    char    **split;
    char    *line;

    cpmap = NULL;
    fd = open(filename, O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        cpmap = ft_strjoin(cpmap, line);
        free(line);
        line = get_next_line(fd);
    }
    split = ft_split(cpmap, '\n');
    free(cpmap);
    return (split);
}