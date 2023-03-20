/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:07:59 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/20 13:29:27 by phelebra         ###   ########.fr       */
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

