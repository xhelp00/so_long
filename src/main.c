/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:18:41 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 17:12:50 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init(t_game *game)
{
	game->map = get_map(game->map_arg, game);
	game->h = (game->map.h) * 32;
	game->w = (game->map.w) * 32;
	game->i = 0;
	game->frames = 0;
	game->counter_img = NULL;
	game->collectible = (t_collectible *)malloc(sizeof(t_collectible));
	if (!game->collectible)
		exit(0);
	game->col = 0;
	game->collected = 0;
	game->open = 0;
	check_path(game, game->map_arg);
	game->grid = game->map.grid;
	game->mlx = mlx_init(game->w, game->h, "So Long!", true);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	check_arguments(ac, av, game);
	init(game);
	init_movements(game);
	init_idle_texture(game);
	init_tile_textures(game);
	load_collectibles(game);
	draw_tiles(game);
	draw_collectibles(game);
	add_player(game);
	put_door(game);
	put_enemy(game);
	mlx_loop_hook(game->mlx, idle_animation_p, game);
	mlx_key_hook(game->mlx, hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	system("leaks so_long");
	return (0);
}
