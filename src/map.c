/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:17 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/17 15:16:45 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	empty_game(t_game *game)
{
	game->grid = (void *)0;
	game->h = 0;
	game->w = 0;
	game->count_collect = 0;
	game->count_exit = 0;
	game->count_player = 0;
	game->allowed_symbols = "PEC01B";
}

t_game	get_map(char *map)
{
	t_game	game_map;
	int		fd;
	char 	*grid;
	char 	*line;

	fd = open(map, O_RDONLY);
	grid = ft_strdup("");
	line = get_next_line(fd);
	empty_game(&game_map);
	while (line != NULL)
	{
		grid = ft_strjoingnl(grid, line);
		ft_printf("%s", line); //test to see loaded map * remove
		free(line);
		line = get_next_line(fd);
		game_map.h++;
	}
	game_map.grid = ft_split(grid, '\n');
	if (game_map.grid[0])
		game_map.w = ft_strlen(game_map.grid[0]);
	check_grid_symbols(&game_map);
	//free grid and line
	ft_printf("%d\n%d\n", game_map.h, game_map.w); // test to see calculated dimensions
	close(fd);
	return (game_map);
}
