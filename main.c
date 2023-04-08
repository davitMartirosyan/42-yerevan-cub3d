/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:49:41 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/08 04:42:03 by tumolabs         ###   ########.fr       */
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
        printf("everything is okay\n");
        // run(table);
    }
}

//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