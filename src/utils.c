/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:07:02 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/08 03:55:22 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int rgb(char *line)
{
    int     rgb;
    char    **split;
    
    replace_non_integers(line, 3);
    split = ft_split(line, 3);
    rgb = (ft_atoi(split[0]) << 16) | (ft_atoi(split[1]) << 8) | ft_atoi(split[2]);
    free_char_pp(&split);
    return (rgb);
}

void    replace_non_integers(char *line, int to)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (!ft_isdigit(line[i]))
            line[i] = to;
        i++;
    }
}

void    replace_all(char *line)
{
    int i;

    i = -1;
    while (line[++i])
        line[i] = '-';
}

int	head_bottom(char *string)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] == '1' || ft_isspace(string[i]))
			continue;
		else
			return (0);
	}
	return (1);
}

int	middle(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i][0] == '1' && map[i][ft_strlen(map[i]) - 1] == '1')
			continue;
		else
			return (0);	
	}
	return (1);
}
