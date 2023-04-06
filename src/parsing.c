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

void    texture_line(char *line, t_table *table)
{
    int i;
    i = 0;
    while (line[i])
    {
        if (ft_isspace(line[i]))
        {
            i++;
            continue;
        }
        else if (ft_toupper(line[i]) == 'N' && ft_toupper(line[i + 1]) == 'O')
            table->north = ft_strjoin(table->north, line+i+2);
        else if (ft_toupper(line[i]) == 'S' && ft_toupper(line[i + 1]) == 'O')
            table->south = ft_strjoin(table->south, line+i+2);
        else if (ft_toupper(line[i]) == 'W' && ft_toupper(line[i + 1]) == 'E')
            table->west = ft_strjoin(table->west, line+i+2);
        else if (ft_toupper(line[i]) == 'E' && ft_toupper(line[i + 1]) == 'A')
            table->east = ft_strjoin(table->east, line+i+2);
        i++;
    }
}

int not_isset_textures(t_table *table)
{
    if (!table->north || !table->south ||
        !table->east || !table->west)
        return (1);
    return (0);
}

int parser(t_table *table, char *filename)
{
    char    *line;
    int     fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        failure(-2);
    line = get_next_line(fd);
    while (line != NULL)
    {
        texture_line(line, table);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close (fd);
    if (not_isset_textures(table))
        return (0);
    fd = open(filename, O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        floor_ceiling(line, table);
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return (1);
}

void    floor_ceiling(char *line, t_table *table)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (ft_isspace(line[i]))
        {
            i++;
            continue;
        }
        else if (ft_toupper(line[i]) == 'F')
            table->f = rgb(line);
        else if (ft_toupper(line[i]) == 'C')
            table->c = rgb(line);
        i++;
    }
}