/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:32:39 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/20 18:02:04 by phelebra         ###   ########.fr       */
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
	mlx_image_to_window((game)->mlx, image->exit_img[0],
		exit->x * TILE, exit->y * TILE);
	free(exit);
}
/* 
void	put_enemy(t_game *game)
{
	t_texture		*image;
	t_position		*bot;

	bot = get_component((game)->grid, 'B');
	image = (game)->idle_e->idle_texture;
	mlx_image_to_window((game)->mlx, image->enemy_img[0],
		bot->x * TILE, bot->y * TILE);
	free(exit);
} */