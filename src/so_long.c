/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:18:00 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 16:57:14 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_collectible_count(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->grid[++y])
	{
		x = -1;
		while (game->grid[y][++x])
			if (game->grid[y][x] == 'C')
				game->col++;
	}
}

void	player_is_on_colectible(t_game *game)
{
	mlx_image_t	*player;
	int			posx;
	int			posy;

	player = game->idle_p->idle;
	posx = player->instances[0].x / TILE;
	posy = player->instances[0].y / TILE;
	if ((game)->grid[posy][posx] == 'C')
		collect(game, posx, posy);
	if ((game->grid[posy][posx]) == 'E' && game->open)
		win(game);
}

void	collect(t_game *game, int posx, int posy)
{
	int	i;

	i = 0;
	while (i < (game->map.count_collect))
	{
		if (game->collectible->collectible_img->instances[i].x
			== game->idle_p->idle->instances[0].x
			&& game->collectible->collectible_img->instances[i].y
			== game->idle_p->idle->instances[0].y)
			game->collectible->collectible_img->instances[i].enabled = 0;
		i++;
	}
	game->grid[posy][posx] = '0';
	game->collected += 1;
	if (game->collected == game->map.count_collect)
	{
		game->open = 1;
		mlx_delete_image(game->mlx, game->tiles->exit_img[0]);
	}
}

void	win(t_game *game)
{
	ft_printf("Game complete, YOU WIN! %d coins collected.\n", game->collected);
	ft_printf("\n+-------------------------------------------------+\n");
	ft_printf("+  Thank you for playing my first game!! <3  <3   +\n");
	ft_printf("+-------------------------------------------------+\n");
	mlx_close_window(game->mlx);
}

void	loose(t_game *game)
{
	ft_printf("GAME OVER! %d coins collected before you have awfully died..\n",
		game->collected);
	mlx_close_window(game->mlx);
}
