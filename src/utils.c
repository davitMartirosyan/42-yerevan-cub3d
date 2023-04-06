/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:07:02 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/06 12:45:11 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int rgb(char *line)
{
    int     rgb;
    char    **split;
    
    replace_non_integers(line);
    split = ft_split(line, 3);
    rgb = (ft_atoi(split[0]) << 16) | (ft_atoi(split[1]) << 8) | ft_atoi(split[2]);
    free_char_pp(&split);
    return (rgb);
}

void    replace_non_integers(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (!ft_isdigit(line[i]))
            line[i] = 3;
        i++;
    }
}