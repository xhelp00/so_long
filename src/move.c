/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:42:19 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/21 13:48:45 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_move(t_game *game, t_position *movement)
{
	mlx_instance_t	*player;
	int				posx;
	int				posy;

	posx = movement->x;
	posy = movement->y;
	player = game->idle_p->idle->instances;
	posx = posx + player->x / TILE;
	posy = posy + player->y / TILE;
	if (game->grid[posy][posx] != '1')
		return (1);
	return (0);
}

void	init_movements(t_game *game)
{
	(game)->movement[0] = (t_position *)malloc(sizeof(t_position));
	(game)->movement[1] = (t_position *)malloc(sizeof(t_position));
	(game)->movement[2] = (t_position *)malloc(sizeof(t_position));
	(game)->movement[3] = (t_position *)malloc(sizeof(t_position));
	(game)->movement[4] = NULL;
	(game)->movement[0]->x = 0;
	(game)->movement[0]->y = -1;
	(game)->movement[1]->x = 0;
	(game)->movement[1]->y = 1;
	(game)->movement[2]->x = 1;
	(game)->movement[2]->y = 0;
	(game)->movement[3]->x = -1;
	(game)->movement[3]->y = 0;
}

void	function_move(t_game *game, t_position *position)
{
	mlx_image_t		*player_img;
	static int		move;

	player_img = game->idle_p->idle;
	if (is_valid_move(game, position))
	{	
		player_img->instances[0].y += position->y * TILE;
		player_img->instances[0].x += position->x * TILE;
		move++;
		ft_printf("Moves: %d\n", move);
	}
}