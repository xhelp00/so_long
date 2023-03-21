/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:07:59 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/21 17:24:59 by phelebra         ###   ########.fr       */
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
	int	y = 0;
	int	x = 0;

	y = -1;
	while ((game)->grid[++y])
	{
		x = -1;
		while ((game)->grid[y][++x])
			put_collectible(game, (game)->grid[y][x], x * TILE, y * TILE);
	}
}