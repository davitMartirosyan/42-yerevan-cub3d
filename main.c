/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:49:41 by tumolabs          #+#    #+#             */
/*   Updated: 2023/04/06 02:03:29 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int ac, char **av)
{
    t_table     *table;
    
    if (ac < 2 || ac > 2)
        failure(-1);
    init(&table);
    if (parser(table, av[1]))
    {
        // run();
    }
    printf("%d\n", table->map_w);
}


int parser(t_table *table, char *filename)
{
    char    *line;
    int     fd;
    int     i;

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
    printf("%s", table->north);
    printf("%s", table->south);
    printf("%s", table->west);
    return (0);
}

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
        else if (line[i] == 'N' && line[i + 1] == 'O')
            table->north = ft_strjoin(table->north, line+i+2);
        else if (line[i] == 'S' && line[i + 1] == 'O')
            table->south = ft_strjoin(table->south, line+i+2);
        else if (line[i] == 'W' && line[i + 1] == 'E')
            table->west = ft_strjoin(table->west, line+i+2);
        else if (line[i] == 'E' && line[i + 1] == 'A')
            table->east = ft_strjoin(table->east, line+i+2);
        i++;
    }
}


