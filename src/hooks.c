/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:05:41 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 15:49:54 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	idle_animation_p(void *param)
{
	t_game			*game;
	mlx_image_t		*player;
	mlx_image_t		*bot;

	game = param;
	player = game->idle_p->idle;
	bot = game->idle_e->idle;

	if (game->frames == 0 || game->frames % 3 == 0)
	{
		ft_memcpy(player->pixels, game->idle_p->idle_img[game->i]->pixels,
			32 * 32 * 4);
		ft_memcpy(bot->pixels, game->idle_e->idle_img[game->i]->pixels,
			32 * 32 * 4);
		if (game->i == 3)
		{
			game->frames = -1;
			game->i = -1;
		}
		game->i++;
	}
	game->frames++;
}

void hook(mlx_key_data_t key, void* param)
{
	t_game* game = param;

	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		ft_printf("You have left the game.\n");
		get_collectible_count(game);
		ft_printf("Collectibles left: %d\n", game->col);
	}
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		function_move(game, game->movement[0]);
	if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		function_move(game, game->movement[1]);
	if (key.key ==MLX_KEY_LEFT && key.action == MLX_PRESS)
		function_move(game, game->movement[3]);
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		function_move(game, game->movement[2]);
}

void	player_is_on_enemy(t_game *game)
{
	mlx_image_t	*player;
	int				posx;
	int				posy;

	player = game->idle_p->idle;
	posx = player->instances[0].x / TILE;
	posy = player->instances[0].y / TILE;
	if ((game)->grid[posy][posx] == 'B')
		loose(game);
}
