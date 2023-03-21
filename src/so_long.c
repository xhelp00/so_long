/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:18:00 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/21 17:46:18 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_collectible_count(t_game *game)
{

	int	y;
	int	x;

	y = -1;
	while ((game)->grid[++y])
	{
		x = -1;
		while ((game)->grid[y][++x])
			if (game->grid[y][x] == 'C')
				game->col++;
	}
}
