/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:56:17 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/15 16:57:12 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	empty_map(t_map *map)
{
	map->grid = (void *)0;
	map->h = 0;
	map->w = 0;
}

t_map	get_map(char *map)
{
	t_map	game_map;
	int		fd;
	char 	*grid;
	char 	*line;

	fd = open(map, O_RDONLY);
	grid = ft_strdup("");
	line = get_next_line(fd);
	empty_map(&game_map);
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
	//checks for map
	//free grid and line

	ft_printf("%d\n%d\n", game_map.h, game_map.w); // test to see calculated dimensions

	close(fd);
	return (game_map);
}
