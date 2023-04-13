/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 00:33:47 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/13 02:04:36 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    init(t_game **game, t_player **player)
{
    (*game) = ft_calloc(19, sizeof(t_game));
	(*player) = ft_calloc(3, sizeof(t_player));
		
}