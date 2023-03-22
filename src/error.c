/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:12:37 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 17:06:25 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	whatsup(int i)
{
	if (i == 1)
		ft_printf("ERROR\nMessage: Map is not right-angled.\n");
	else if (i == 2)
		ft_printf("ERROR\nMessage: Map has invalid characters.\n");
	else if (i == 3)
		ft_printf("ERROR\nMessage: Map has no valid path.\n");
	else if (i == 4)
		ft_printf("ERROR\nMessage: Map is not surrounded by walls.\n");
	else if (i == 5)
		ft_printf("ERROR\nMessage: Checking in game objects failed.\n");
	exit (0);
}

void	add_player(t_game *game)
{
	int			posx;
	int			posy;
	t_position	*player_pos;

	player_pos = get_component((game)->grid, 'P');
	posx = player_pos->x * TILE;
	posy = player_pos->y * TILE;
	mlx_image_to_window((game)->mlx, (game)->idle_p->idle, posx, posy);
	free(player_pos);
}
