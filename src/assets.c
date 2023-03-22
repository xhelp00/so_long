/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:12:24 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 11:02:07 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_idle_images(t_game *game)
{
	t_idle	*idle;

	idle = (game)->idle_p;
	idle->idle_img[0] = mlx_texture_to_image((game)->mlx, &idle->idle_texture[0]->texture);
	idle->idle_img[1] = mlx_texture_to_image((game)->mlx, &idle->idle_texture[1]->texture);
	idle->idle_img[2] = mlx_texture_to_image((game)->mlx, &idle->idle_texture[2]->texture);
	idle->idle_img[3] = mlx_texture_to_image((game)->mlx, &idle->idle_texture[3]->texture);
	idle->idle_img[4] = NULL;
	idle->idle = mlx_texture_to_image((game)->mlx, &idle->idle_texture[0]->texture);
	idle = (game)->idle_e;
	idle->idle_img[0] = mlx_texture_to_image((game)->mlx, &idle->idle_texture[0]->texture);
	idle->idle_img[1] = mlx_texture_to_image((game)->mlx, &idle->idle_texture[1]->texture);
	idle->idle_img[2] = mlx_texture_to_image((game)->mlx, &idle->idle_texture[2]->texture);
	idle->idle_img[3] = mlx_texture_to_image((game)->mlx, &idle->idle_texture[3]->texture);
	idle->idle_img[4] = NULL;
	idle->idle = mlx_texture_to_image((game)->mlx, &idle->idle_texture[0]->texture);
}

void	delete_idle_textures(t_game *game)
{
	t_idle	*idle;
	
	idle = (game)->idle_p;
	mlx_delete_xpm42(idle->idle_texture[0]);
	mlx_delete_xpm42(idle->idle_texture[1]);
	mlx_delete_xpm42(idle->idle_texture[2]);
	mlx_delete_xpm42(idle->idle_texture[3]);
	idle = (game)->idle_e;
	mlx_delete_xpm42(idle->idle_texture[0]);
	mlx_delete_xpm42(idle->idle_texture[1]);
	mlx_delete_xpm42(idle->idle_texture[2]);
	mlx_delete_xpm42(idle->idle_texture[3]);
}

void	init_idle_texture(t_game *game)
{
	t_idle	*idle;

	(game)->idle_p = (t_idle *)malloc(sizeof(t_idle));
	idle = (game)->idle_p;
	idle->idle_texture[0] = mlx_load_xpm42("./sprites/player/tile000.xpm42");
	idle->idle_texture[1] = mlx_load_xpm42("./sprites/player/tile001.xpm42");
	idle->idle_texture[2] = mlx_load_xpm42("./sprites/player/tile002.xpm42");
	idle->idle_texture[3] = mlx_load_xpm42("./sprites/player/tile003.xpm42");
	idle->idle_texture[4] = NULL;
	
	(game)->idle_e = (t_idle *)malloc(sizeof(t_idle));
	idle = (game)->idle_e;
	idle->idle_texture[0] = mlx_load_xpm42("./sprites/bot/tile000.xpm42");
	idle->idle_texture[1] = mlx_load_xpm42("./sprites/bot/tile001.xpm42");
	idle->idle_texture[2] = mlx_load_xpm42("./sprites/bot/tile002.xpm42");
	idle->idle_texture[3] = mlx_load_xpm42("./sprites/bot/tile003.xpm42");
	idle->idle_texture[4] = NULL;
	load_idle_images(game);
	delete_idle_textures(game);
}

void	load_tile_images(t_game *game)
{
	t_texture	*tiles;
	mlx_t		*mlx;

	mlx = (game)->mlx;
	tiles = (game)->tiles;
	tiles->floor_img = mlx_texture_to_image(mlx, &tiles->floor->texture);
	tiles->wall_img = mlx_texture_to_image(mlx, &tiles->wall->texture);
	tiles->exit_img[0] = mlx_texture_to_image(mlx, &tiles->exit[0]->texture);
	tiles->exit_img[1] = mlx_texture_to_image(mlx, &tiles->exit[1]->texture);
	tiles->enemy_img[0] = mlx_texture_to_image(mlx,&tiles->enemy[0]->texture);
	tiles->enemy_img[1] = mlx_texture_to_image(mlx,&tiles->enemy[1]->texture);
	tiles->enemy_img[2] = mlx_texture_to_image(mlx,&tiles->enemy[2]->texture);
	tiles->enemy_img[3] = mlx_texture_to_image(mlx,&tiles->enemy[3]->texture);
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

void	init_tile_textures(t_game *game)
{
	t_texture	*tiles;

	(game)->tiles = (t_texture *)malloc(sizeof(t_texture));
	tiles = (game)->tiles;
	tiles->floor = mlx_load_xpm42("./sprites/ground/tile000.xpm42");
	tiles->wall = mlx_load_xpm42("./sprites/wall/tile021.xpm42");
	tiles->exit[0] = mlx_load_xpm42("./sprites/exit/closed.xpm42");
	tiles->exit[1] = mlx_load_xpm42("./sprites/exit/open.xpm42");
	tiles->enemy[0] = mlx_load_xpm42("./sprites/bot/tile000.xpm42");
	tiles->enemy[1] = mlx_load_xpm42("./sprites/bot/tile001.xpm42");
	tiles->enemy[2] = mlx_load_xpm42("./sprites/bot/tile002.xpm42");
	tiles->enemy[3] = mlx_load_xpm42("./sprites/bot/tile003.xpm42");
	load_tile_images(game);
	delete_tile_textures(game);
}
