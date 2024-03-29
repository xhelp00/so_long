/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:17 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 11:14:27 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	empty_game(t_map *map, t_game *game)
{
	game->grid = (void *)0;
	map->grid = (void *)0;
	game->h = 0;
	game->w = 0;
	map->h = 0;
	map->w = 0;
	map->count_collect = 0;
	map->count_exit = 0;
	map->count_player = 0;
	map->allowed_symbols = "PEC01B";
}

t_map	get_map(char *map, t_game *game)
{
	t_map	game_map;
	int		fd;
	char	*grid;
	char	*line;

	fd = open(map, O_RDONLY);
	grid = ft_strdup("");
	line = get_next_line(fd);
	empty_game(&game_map, game);
	while (line != NULL)
	{
		grid = ft_strjoingnl(grid, line);
		free(line);
		line = get_next_line(fd);
		game_map.h++;
	}
	game_map.grid = ft_split(grid, '\n');
	if (game_map.grid[0])
		game_map.w = ft_strlen(game_map.grid[0]);
	check_grid_symbols(&game_map);
	free_chars(&grid, &line);
	close(fd);
	return (game_map);
}
