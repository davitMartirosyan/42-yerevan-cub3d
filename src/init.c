/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 00:33:47 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/12 00:34:57 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    init(t_table **table, t_player **player)
{
    (*table) = ft_calloc(16, sizeof(t_table));
	(*player) = ft_calloc(3, sizeof(t_player));
		
}