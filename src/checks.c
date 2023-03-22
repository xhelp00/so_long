/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:05:59 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 16:51:04 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	suffix_check(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (s[len - 4] == '.' && s[len - 3] == 'b' && \
	s[len - 2] == 'e' && s[len - 1] == 'r')
		return (1);
	return (0);
}

void	check_arguments(int ac, char **av, t_game *g)
{
	if (ac > 2)
	{
		ft_printf("ERROR\nMessage: Too many arguments.\n");
		exit(0);
	}
	else if (ac == 1)
	{
		ft_printf("ERROR\nMessage: Too few arguments.\n");
		exit(0);
	}
	else if (suffix_check(av[1]) == 0)
	{
		ft_printf("ERROR\nMessage: Map file has to be .ber format.\n");
		exit(0);
	}
	g->map_arg = av[1];
}

void	check_around(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		if (ft_strlen(map->grid[j]) != ft_strlen(map->grid[i]))
			whatsup(1);
		while (map->grid[i][j])
		{
			if (i == 0 || i == map->h - 1 || j == 0 || j == map->w - 1)
			{
				if (map->grid[i][j] != '1')
					whatsup(4);
			}
			j++;
		}
		i++;
	}
}

void	check_grid_symbols(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < map->h)
	{
		while (++x < map->w)
		{
			if (map->grid[y][x] == 'P')
				map->count_player += 1;
			if (map->grid[y][x] == 'E')
				map->count_exit += 1;
			if (map->grid[y][x] == 'C')
				map->count_collect += 1;
			if (!(ft_strchr(map->allowed_symbols, (int)map->grid[y][x])))
				whatsup(2);
		}
		x = -1;
	}
	if (map->count_collect < 1 || map->count_player != 1
		|| map->count_exit != 1)
		whatsup(5);
	check_around(map);
}
