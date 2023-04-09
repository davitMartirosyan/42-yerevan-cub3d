/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:49:41 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/09 04:52:28 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int ac, char **av)
{
    t_table     *table;
    
    if (ac < 2 || ac > 2)
        failure(1);
    init(&table);
    if (parser(table, av[1]))
    {
        printf("everything is okay\n");
        // run(table);
		int x = 0;
		int y = 0;
		while (y < table->map_h)
		{
			x = 0;
			while (x < table->map_w)
			{
				if (table->mmap[y][x] == 1)
					printf("\033[0;30m{%d}", table->mmap[y][x]);
				else if (table->mmap[y][x] == 0)
					printf("\033[0;32m{%d}", table->mmap[y][x]);
				else if (table->mmap[y][x] == -1)
					printf("\033[0;30m{%d}", table->mmap[y][x]);
				else
					printf("\033[0;35m{%d}", table->mmap[y][x]);
					
				x++;
			}
			printf("\n");
			y++;
		}
    }
	else
	{
		// free_table(table);
		failure(1);
	}
	// return (0);
}

//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