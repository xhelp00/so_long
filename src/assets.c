/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:12:24 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/19 15:25:19 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_idle_images(t_game *game)
{
	t_idle	*idle;

	idle = (game)->idle;
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
	
	idle = (game)->idle;
	mlx_delete_xpm42(idle->idle_texture[0]);
	mlx_delete_xpm42(idle->idle_texture[1]);
	mlx_delete_xpm42(idle->idle_texture[2]);
	mlx_delete_xpm42(idle->idle_texture[3]);
}

void	init_idle_texture(t_game *game)
{
	t_idle	*idle;

	(game)->idle = (t_idle *)malloc(sizeof(t_idle));
	idle = (game)->idle;
	idle->idle_texture[0] = mlx_load_xpm42("./sprites/player/tile000.xpm42");
	idle->idle_texture[1] = mlx_load_xpm42("./sprites/player/tile001.xpm42");
	idle->idle_texture[2] = mlx_load_xpm42("./sprites/player/tile002.xpm42");
	idle->idle_texture[3] = mlx_load_xpm42("./sprites/player/tile003.xpm42");
	idle->idle_texture[4] = NULL;
	load_idle_images(game);
	delete_idle_textures(game);
}
