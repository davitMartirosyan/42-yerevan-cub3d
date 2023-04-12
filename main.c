/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:49:41 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/12 05:12:47 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
void	draw_map(t_table *table, t_player *player);
void	run(t_table *table, t_player *player);
void	draw_rect(void *mlx_ptr, void *win_ptr, int x, int y, int width, int height, int color);

int main(int ac, char **av)
{
    t_table     *table;
    t_player	*player;
	
    if (ac < 2 || ac > 2)
        failure(1);
    init(&table, &player);
    if (parser(table, av[1]))
		run(table, player);
	else
	{
		// free_table(table);
		failure(1);
	}
	// return (0);
}

//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

void	run(t_table *table, t_player *player)
{
	find_player_position(table, &player);
	draw_map(table, player);
	
}

void	draw_map(t_table *table, t_player *player)
{
	int	x;
	int	y;
	void	*mlx;
	void	*win;
	
	y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Cub3d");
	while (y < table->map_h)
	{
		x = 0;
		while (x < table->map_w)
		{
			int i = x * 10;
			int	j = y * 10;
			if (table->mmap[y][x] == 1)
				draw_rect(mlx, win, i, j, 10, 10, 0x00aaddff);
			else
				draw_rect(mlx, win, i, j, 10, 10, 0x004411ff);
			x++;				
		}
		y++;
	}
	mlx_loop(mlx);
}


void draw_rect(void *mlx_ptr, void *win_ptr, int x, int y, int width, int height, int color)
{
    int i, j;

    for (i = x; i < x + width; i++) {
        for (j = y; j < y + height; j++) {
            mlx_pixel_put(mlx_ptr, win_ptr, i, j, color);
        }
    }
}



void	find_player_position(t_table *table, t_player **player)
{
	int	x;
	int	y;

	y = 0;
	while (y < table->map_h)
	{
		x = 0;
		while (x < table->map_w)
		{
			if (table->mmap[y][x] == 30 || table->mmap[y][x] == 35
				|| table->mmap[y][x] == 21 || table->mmap[y][x] == 39)
			{
				(*player)->pos.x = x;
				(*player)->pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}