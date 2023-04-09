/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 01:33:06 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/09 04:41:08 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	parser(t_table *table, char *filename)
{
    char    **cmap;

    cmap = copymap(filename);
	if (!cmap
		|| !textured(cmap, table)
		|| !floor_ceiling(cmap, table)
		|| !__set(cmap, table)
		|| !checked(table->map, table)
		|| !redefine(table)
		|| !convert(table)
		|| board_is_oppend(table))
	{
		// free_table(table);
    	free_char_pp(&cmap);
		return (0);
	}
    free_char_pp(&cmap);
	return (1);
}

int	board_is_oppend(t_table *table)
{
	int	x;
	int	y;

	y = 0;
	while (y < table->map_h)
	{
		x = 0;
		while (x < table->map_w)
		{
			if (y > 0 && x > 0
				&& table->mmap[y][x] == 0
				&& table->mmap[y - 1][x] && table->mmap[y - 1][x] == -1)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	convert(t_table *table)
{
	char	**split;
	int		x;
	int		y;

	y = 0;
	split = ft_split(table->map, '\n');
	while (y < table->map_h)
	{
		x = 0;
		while (x < table->map_w)
		{
			if (split[y][x] == 0)
				break;
			else if (ft_isspace(split[y][x]))
			{
				x++;
				continue;
			}
			table->mmap[y][x] = split[y][x] - '0';
			x++;
		}
		y++;
	}
	free_char_pp(&split);
	return (1);
}

int	redefine(t_table *table)
{
	int	x;
	int	y;
	
	y = 0;
	table->mmap = malloc(sizeof(int *) * table->map_h);
	if (!table->mmap)
		return (0);
	while (y <= table->map_h)
	{
		x = 0;
		table->mmap[y] = malloc(sizeof(int) * table->map_w + 1);
		while (x <= table->map_w)
		{
			table->mmap[y][x] = -1;
			x++;
		}
		table->mmap[y][x] = 0;
		y++;
	}
	table->mmap[y] = 0;
	return (1);
}

int	checked(char *map, t_table *table)
{
	int		i;
	char	**split_map;

	split_map = ft_split(map, '\n');
	table->map_h = height(split_map);
	table->map_w = width(split_map);
	if (!head_bottom(split_map[0]) || !head_bottom(split_map[table->map_h - 1])
		|| !middle(split_map) || !middle_points(split_map))
	{
		free_char_pp(&split_map);
		return (0);
	}
	return (1);
}

int	middle_points(char **map)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] >= '0' && map[i][j] <= '9') || ft_isspace(map[i][j]))
				continue;
			else if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				player++;
			else
				return (0);
		}
	}
	if (player > 1)
		return (0);
	return (1);
}

int	textured(char **cmap, t_table *table)
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

void	split_function(char **cmap, int i, int j, t_table *table)
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

char	**copymap(char *filename)
{
    int		fd;
    char	*cpmap;
    char	**split;
    char	*line;

    cpmap = NULL;
    fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
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