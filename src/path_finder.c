/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:04:08 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/17 14:45:40 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(int x, int y, t_flood *flood, t_game *g)
{
	if (flood->map[y][x] == '1')
		return ;
	if (flood->map[y][x] != 'f')
	{
		if (flood->map[y][x] == 'C')
			flood->count_collect -= 1;
		if (flood->map[y][x] == 'E')
			flood->exit_found = true;
		flood->map[y][x] = 'f';
		flood_fill(x - 1, y, flood, g);
		flood_fill(x, y + 1, flood, g);
		flood_fill(x + 1, y, flood, g);
		flood_fill(x, y - 1, flood, g);
	}
}

char	**generate_map_flood(char *input_file)
{
	int		fd;
	char	*line;
	char	*joined_lines;
	char	**ret;

	line = "";
	joined_lines = ft_strdup("");
	fd = open (input_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		joined_lines = ft_strjoingnl(joined_lines, line);
		free (line);
	}
	free (line);
	close(fd);
	ret = ft_split(joined_lines, '\n');
	free (joined_lines);
	return (ret);
}

void	init_flood(char *input_file, t_flood *flood)
{
	flood->map = generate_map_flood(input_file);
	flood->rows = 0;
	flood->cols = 0;
	flood->count_collect = 0;
	flood->p_x = 0;
	flood->p_y = 0;
	flood->exit_found = false;
	while (flood->map[flood->rows])
		flood->rows += 1;
	while (flood->map[0][flood->cols])
		flood->cols += 1;
}

void	find_pc(t_flood *flood)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < flood->rows)
	{
		while (x < flood->cols)
		{
			if (flood->map[y][x] == 'C')
				flood->count_collect += 1;
			if (flood->map[y][x] == 'P')
			{
				flood->p_x = x;
				flood->p_y = y;
			}
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

void	check_path(t_game *g, char *input_file)
{
	t_flood		*flood;

	flood = (t_flood *)malloc(sizeof(t_flood));
	if (!flood)
		whatsup(5);
	init_flood(input_file, flood);
	find_pc(flood);
	flood_fill(flood->p_x, flood->p_y, flood, g);
	if (!(flood->count_collect == 0 && flood->exit_found == true))
	{
		free_flood(flood);
		whatsup(3);
	}
	free_flood(flood);
}
