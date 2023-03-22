/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:05:05 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/22 12:01:11 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_free(void *param)
{
	if (param)
		free (param);
	param = 0;
	return (0);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_free(arr[i]);
		i++;
	}
	free(arr);
	arr = 0;
}

void	free_flood(t_flood *flood)
{
	free_array(flood->map);
	ft_free(flood);
}

void	free_chars(char **grid, char **line)
{
	free(*grid);
	free(*line);
}

t_position	*get_component(char **map, char type)
{
	int			x;
	int			y;
	t_position	*pos;

	y = -1;
	pos = (t_position *)malloc(sizeof(t_position));
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == type)
			{
				pos->x = x;
				pos->y = y;
				return (pos);
			}
		}
	}
	return (NULL);
}
