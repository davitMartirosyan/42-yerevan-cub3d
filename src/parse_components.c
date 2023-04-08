/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:30:50 by tumolabs          #+#    #+#             */
/*   Updated: 2023/04/08 03:59:29 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	width(char **map)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (map[++i])
		if (max < (int)ft_strlen(map[i]))
			max = ft_strlen(map[i]);
	return (max);
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

int	floor_ceiling(char **cmap, t_table *table)
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

int	__set(char **cmap, t_table *table)
{
    int i;
    int j;

    i = 0;
    while (cmap[i])
    {
        if (!ft_strchr(cmap[i], '-'))
        {
            table->map = set_map(table->map, '\n', cmap[i]);
            i++;
            continue;
        }
        i++;
    }
    return (1);
}