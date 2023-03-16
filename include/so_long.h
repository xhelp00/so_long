/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:18:14 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/16 09:12:17 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include <sys/errno.h>
# include <fcntl.h>
# include <stddef.h>

typedef struct s_map
{
	int		w;
	int		h;
	char	**grid;
}			t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*game_ptr;
	char	*map_arg;
	int		w;
	int		h;
	t_map	map;
}			t_game;

void	check_arguments(int ac, char **av, t_game *game);
//int		suffix_check(char *s);
t_map	get_map(char *map);
void	whatsup(int i);

#endif