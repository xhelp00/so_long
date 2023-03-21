/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:05:41 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/21 13:38:09 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	idle_animation(void *param)
{
	t_game			*game;
	mlx_image_t		**player;

	game = param;
	player = game->idle_p->idle_img;
	if (game->frames == 0 || game->frames % 3 == 0)
	{
		ft_memcpy(player[0]->pixels, player[game->i]->pixels,
			SPRITE * SPRITE *4);
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

	//idle_animation(game);

	/* if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->idle_p->idle->instances[0].y -= 32;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->idle_p->idle->instances[0].y += 32;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->idle_p->idle->instances[0].x -= 32;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->idle_p->idle->instances[0].x += 32; */

	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		function_move(game, game->movement[0]);
	if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		function_move(game, game->movement[1]);
	if (key.key ==MLX_KEY_LEFT && key.action == MLX_PRESS)
		function_move(game, game->movement[3]);
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		function_move(game, game->movement[2]);
	 
}

