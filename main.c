/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:49:41 by dmartiro          #+#    #+#             */
/*   Updated: 2023/04/13 05:51:35 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int main(int ac, char **av)
{
    t_game     *game;
    t_player	*player;
	
    if (ac < 2 || ac > 2)
        failure(1);
    init(&game, &player);
	game->screen.mlx = mlx_init();
	game->screen.win = mlx_new_window(game->screen.mlx, WIDTH, HEIGHT, "Cub3d");
	game->player = player;
    if (parser(game, av[1]))
		setup(game, player);
	else
		failure(1);
	
	mlx_loop(game->screen.mlx);
	return (0);
}

void	setup(t_game *game, t_player *player)
{
	find_player_position(game, player);
	find_player_direction(game, player);
	play(game);
	write(1, "end of main\n", 12);
}

void	find_player_position(t_game *game, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			if (game->mmap[y][x] == 30
				|| game->mmap[y][x] == 35
				|| game->mmap[y][x] == 21
				|| game->mmap[y][x] == 39)
			{
				player->pos.x = x;
				player->pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	find_player_direction(t_game *game, t_player *player)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			if (game->mmap[y][x] == 30)
			{
				player->dir.x = 0;
				player->dir.y = -1;
				player->plane.x = 0.66 * player->dir.y;
				player->plane.y = -0.66 * player->dir.x;
				return;
			}
			else if (game->mmap[y][x] == 35)
			{
				player->dir.x = 0;
				player->dir.y = 1;
				player->plane.x = 0.66 * player->dir.y;
				player->plane.y = -0.66 * player->dir.x;
				return;
			}
			else if (game->mmap[y][x] == 21)
			{
				player->dir.x = 1;
				player->dir.y = 0;
				player->plane.x = 0.66 * player->dir.y;
				player->plane.y = -0.66 * player->dir.x;
				return;
			}
			else if (game->mmap[y][x] == 39)
			{
				player->dir.x = -1;
				player->dir.y = 0;
				player->plane.x = 0.66 * player->dir.y;
				player->plane.y = -0.66 * player->dir.x;
				return;
			}
			x++;
		}
		y++;
	}
}

void	play(t_game *game)
{
	// double posX = 8, posY = 6;
	// double dirX = 1, dirY = 0;
	// double planeX = 0, planeY = 0.66;
	
	write(1, "havayi\n", 7);
	for(int x = 0; x < WIDTH; x++)
	{
		// std::cout << "x - " << x << " ";	
		double cameraX = 2 * x / (double)WIDTH - 1;
		double rayDirX = game->player->dir.x + game->player->plane.x * cameraX;
		double rayDirY = game->player->dir.y + game->player->plane.y * cameraX;
		int mapX = (int)game->player->pos.x;
		int mapY = (int)game->player->pos.y;

		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->player->pos.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->player->pos.x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->player->pos.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->player->pos.y) * deltaDistY;
		}
		while(hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				// std::cout << "sideDistX < sideDistY - " << (sideDistX < sideDistY) << "\n";
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			printf("map[%d][%d] = ", mapY, mapX);
			printf("%d\n", game->mmap[mapY][mapX]);
			if(game->mmap[mapY][mapX] == 1) hit = 1;
		}
		write(1, "qtam\n", 5);
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		int lineHeight = (int)(HEIGHT / perpWallDist);

		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

		printf("x - %d\n", x);
		printf("drawStart - %d\n", drawStart);
		printf("drawEnd - %d\n", drawEnd);
		for (int i = 0; i < drawStart; i++)
		{
			
		}
			mlx_pixel_put(game->screen.mlx, game->screen.win, x, i, 0xd92032);
		for(int i = drawStart; i < drawEnd; ++i)
			mlx_pixel_put(game->screen.mlx, game->screen.win, x, i, 0x0074d7);
		for(int i = drawEnd; i < HEIGHT; ++i)
			mlx_pixel_put(game->screen.mlx, game->screen.win, x, i, 0xf9983e);
		// std::cout << "x - " << x << " ";
		// std::cout << "drawStart - " << drawStart << " ";
		// std::cout << "drawEnd - " << drawEnd << "\n";
    }
}

void draw_map(t_game *game)
{
    int x, y;
    for (y = 0; y < game->map_h; y++) {
        for (x = 0; x < game->map_w; x++) {
            if (game->mmap[y][x] == 1) {
                int rect_x = x * CELL_SIZE;
                int rect_y = y * CELL_SIZE;
                int rect_color = 0xFFF; // white color
                int i, j;
                for (i = rect_x; i < rect_x + CELL_SIZE; i++) {
                    for (j = rect_y; j < rect_y + CELL_SIZE; j++) {
                        mlx_pixel_put(game->screen.mlx, game->screen.win, i, j, rect_color);
                    }
                }
            }
        }
    }
}

void	draw(t_game *game, int x, int y, int poscol, int aroundcol)
{
	// mlx_pixel_put(game->screen.mlx, game->screen.win, x*10, y*10, 0x00ff0000);
	draw_rect(game->screen.mlx, game->screen.win, x*20, y*20, aroundcol);
}

int	keyhook(int	keycode, t_game *game)
{
	if (keycode == 123)
		game->player->pos.x -= 1;
	if (keycode == 124)
		game->player->pos.x += 1;
	if (keycode == 125)
		game->player->pos.y += 1;
	if (keycode == 126)
		game->player->pos.y -= 1;
	if ((int)game->player->pos.y >= HEIGHT)
		game->player->pos.y = 0;
	if ((int)game->player->pos.x >= WIDTH)
		game->player->pos.x = 0;
	mlx_clear_window(game->screen.mlx, game->screen.win);
	play(game);
	return (1);
}

void	draw_rect(void *mlx, void *win, int x, int y, int aroundcol)
{
	int	x1;
	int	y1;

	y1 = y-10;
	while (y1 <= y+10)
	{
		x1 = x-10;
		while (x1 <= x+10)
		{
			// if (x1 == x && y1 == y)
			// {
			// 	x1++;
			// 	continue;
			// }
			mlx_pixel_put(mlx, win, x1, y1, aroundcol);
			x1++;
		}
		y1++;
	}
}