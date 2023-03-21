/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:32:39 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/21 11:33:06 by phelebra         ###   ########.fr       */
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
 
void	put_enemy(t_game *game)
{
	t_texture		*image;
	t_position		*bot;

	bot = get_component((game)->grid, 'B');
	image = (game)->tiles;
	mlx_image_to_window((game)->mlx, image->enemy_img[0],
		bot->x * TILE, bot->y * TILE);
	free(bot);
} 

void	add_player(t_game *game)
{
	int			posx;
	int			posy;
	t_position	*player_pos;

	player_pos = get_component((game)->grid, 'P');
	posx = player_pos->x * TILE;
	posy = player_pos->y * TILE;
	//(game)->idle_p->idle = mlx_new_image((game)->mlx, TILE, TILE);
	//ft_memset((game)->player_img->pixels, 0, TILE * TILE * 4);
	mlx_image_to_window((game)->mlx, (game)->idle_p->idle, posx, posy);
	free(player_pos);
}