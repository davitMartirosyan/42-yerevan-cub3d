/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 01:33:06 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/07 15:16:50 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


int parser(t_table *table, char *filename)
{
    char    **cmap;

    cmap = copymap(filename);
    if (!textured(cmap, table))
        return (0);
    if (!floor_ceiling(cmap, table))
        return (0);
    if (!__set(cmap, table))
        return (0);
    free_char_pp(&cmap);
    printf("%s\n", table->map);
    return (1);
}

int __set(char **cmap, t_table *table)
{
    int i;
    int j;

    i = 0;
    while (cmap[i])
    {
        if (!ft_strchr(cmap[i], '9'))
        {
            table->map = set_map(table->map, '\n', cmap[i]);
            i++;
            continue;
        }
        i++;
    }
    return (1);
}

char	*set_map(char *s1, int delimiter, char *s2)
{
	char	*arguments;
	int		i;
	int		c;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	arguments = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!arguments)
		return (NULL);
	i = -1;
	c = -1;
	while (s1[++i])
		arguments[i] = s1[i];
	arguments[i++] = delimiter;
	while (s2[++c])
		arguments[i++] = s2[c];
	arguments[i] = '\0';
	free(s1);
	s1 = 0;
	return (arguments);
}

int floor_ceiling(char **cmap, t_table *table)
{
    int i;
    int j;
    char **split;

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
            else if (ft_toupper(cmap[i][j]) == 'F')
            {
                table->floor = rgb(cmap[i]);
                replace_all(cmap[i]);
            }
            else if (ft_toupper(cmap[i][j]) == 'C')
            {
                table->sky = rgb(cmap[i]);
                replace_all(cmap[i]);
            }
            j++;
        }
        i++;
    }
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
            split_function(cmap, i, j, table);
            j++;
        }
        i++;
    }
    if (!table->north || !table->south || !table->west || !table->east)
        return (0);
    return (1);
}

void    split_function(char **cmap, int i, int j, t_table *table)
{
    if (cmap[i][j] == 'N' && cmap[i][j + 1] == 'O')
    {
        table->north = ft_strjoin(table->north, cmap[i] + j + 2);
        replace_all(cmap[i]);
    }
    else if (cmap[i][j] == 'S' && cmap[i][j + 1] == 'O')
    {
        table->south = ft_strjoin(table->south, cmap[i] + j + 2);
        replace_all(cmap[i]);
    }
    else if (cmap[i][j] == 'W' && cmap[i][j + 1] == 'E')
    {
        table->west = ft_strjoin(table->west, cmap[i] + j + 2);
        replace_all(cmap[i]);
    }
    else if (cmap[i][j] == 'E' && cmap[i][j + 1] == 'A')
    {
        table->east = ft_strjoin(table->east, cmap[i] + j + 2);
        replace_all(cmap[i]);
    }
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