/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 00:04:49 by tumolabs          #+#    #+#             */
/*   Updated: 2023/04/06 01:37:13 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int failure(int err)
{
    if (err == -1)
    {
        printf("Arguments Error!\n");
        exit(err);
    }
    else if (err == -2)
    {
        printf("File not found!\n");
        exit(err);
    }
    else if (err == -3)
    {
        printf("Not a valid map!\n");
        exit(err);
    }
    return (0);
}