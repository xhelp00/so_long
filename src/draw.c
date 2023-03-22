/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:07:59 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 17:03:13 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_tiles(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while ((game)->grid[++y])
	{
		x = -1;
		while ((game)->grid[y][++x])
			put_floor(game, (game)->grid[y][x], x * TILE, y * TILE);
	}
}

void	draw_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while ((game)->grid[++y])
	{
		x = -1;
		while ((game)->grid[y][++x])
			put_collectible(game, (game)->grid[y][x], x * TILE, y * TILE);
	}
}

void	delete_tile_textures(t_game *game)
{
	t_texture	*tiles;

	tiles = (game)->tiles;
	mlx_delete_xpm42(tiles->floor);
	mlx_delete_xpm42(tiles->wall);
	mlx_delete_xpm42(tiles->exit[0]);
	mlx_delete_xpm42(tiles->exit[1]);
	mlx_delete_xpm42(tiles->enemy[0]);
	mlx_delete_xpm42(tiles->enemy[1]);
	mlx_delete_xpm42(tiles->enemy[2]);
	mlx_delete_xpm42(tiles->enemy[3]);
}

void	load_idle_images2(t_game *game)
{
	t_idle	*idle;

	idle = (game)->idle_e;
	idle->idle_img[0] = mlx_texture_to_image((game)->mlx,
			&idle->idle_texture[0]->texture);
	idle->idle_img[1] = mlx_texture_to_image((game)->mlx,
			&idle->idle_texture[1]->texture);
	idle->idle_img[2] = mlx_texture_to_image((game)->mlx,
			&idle->idle_texture[2]->texture);
	idle->idle_img[3] = mlx_texture_to_image((game)->mlx,
			&idle->idle_texture[3]->texture);
	idle->idle_img[4] = NULL;
	idle->idle = mlx_texture_to_image((game)->mlx,
			&idle->idle_texture[0]->texture);
}
