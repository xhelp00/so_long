/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:32:39 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 17:06:46 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_floor(t_game *game, char c, int width, int height)
{
	t_texture	*tiles;

	tiles = (game)->tiles;
	if (c == '1')
		mlx_image_to_window((game)->mlx, tiles->wall_img, width, height);
	else
		mlx_image_to_window((game)->mlx, tiles->floor_img, width, height);
}

void	put_door(t_game *game)
{
	t_texture		*image;
	t_position		*exit;

	exit = get_component((game)->grid, 'E');
	image = (game)->tiles;
	mlx_image_to_window((game)->mlx, image->exit_img[1],
		exit->x * TILE, exit->y * TILE);
	mlx_image_to_window((game)->mlx, image->exit_img[0],
		exit->x * TILE, exit->y * TILE);
	free(exit);
}

void	put_enemy(t_game *game)
{
	t_texture		*image;
	t_position		*bot;

	bot = get_component((game)->grid, 'B');
	image = (game)->tiles;
	if (bot != NULL)
		mlx_image_to_window((game)->mlx, game->idle_e->idle,
			bot->x * TILE, bot->y * TILE);
	free(bot);
}

void	load_collectibles(t_game *game)
{
	game->collectible->c_x = 0;
	game->collectible->c_y = 0;
	game->collectible->collectible_t = mlx_load_xpm42
		("sprites/goldCoin/goldCoin1.xpm42");
	game->collectible->collectible_img = mlx_texture_to_image(game->mlx,
			&game->collectible->collectible_t->texture);
	game->collectible->idle = mlx_texture_to_image(game->mlx,
			&game->collectible->collectible_t->texture);
}

void	put_collectible(t_game *game, char c, int x, int y)
{
	if (c == 'C')
		mlx_image_to_window(game->mlx,
			game->collectible->collectible_img, x, y);
}
