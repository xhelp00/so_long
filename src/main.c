/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:18:41 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 16:19:45 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	check_arguments(ac, av, game); //init game at first - add structs for player etc, malloc and ending/free functions
	game->map = get_map(game->map_arg, game); //consider changing type
	game->h = (game->map.h) * 32;
	game->w = (game->map.w) * 32;
	game->i = 0;
	game->frames = 0;
	game->counter_img = NULL;
	game->collectible = (t_collectible *)malloc(sizeof(t_collectible));
	if (!game->collectible)
		return (-1);
	game->col = 0;
	game->collected = 0;
	game->open = 0;

	check_path(game, game->map_arg);
	//load_game(game); tbd
	//init game maybe with argv[1] only, init all values out of main fc
	game->grid = game->map.grid;
	if (!(game->mlx = mlx_init(game->w, game->h, "So Long!", true)))
		return(-1);
	init_movements(game);
	init_idle_texture(game); //must go only after mlx_init otherwise SIGSEGV
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
