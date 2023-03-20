/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:05:41 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/20 17:38:01 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	idle_animation(void *param)
{
	t_game			*game;
	mlx_image_t		**player;
	static int		frames;
	static int		i;

	game = param;
	player = game->idle_p->idle_img;
	frames = 0;
	i = 0;
	if (frames == 0 || frames % 3 == 0)
	{
		ft_memcpy(player[0]->pixels, player[i]->pixels,
			SPRITE * SPRITE * 4);
		if (i == 3)
		{
			frames = -1;
			i = -1;
		}
		i++;
	}
	frames++;
}

void hook(void* param)
{
	t_game* game = param;

	//idle_animation(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->idle_p->idle->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->idle_p->idle->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->idle_p->idle->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->idle_p->idle->instances[0].x += 5;
	
}

