/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:18:14 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/17 14:44:56 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include <sys/errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct s_position
{
	int		x;
	int		y;
}			t_position;

typedef struct s_texture
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*enemy[3];
}			t_texture;

typedef struct s_map
{
	int		w;
	int		h;
	//textures
}			t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*player[3];
	void			*game_ptr;
	char			*map_arg;
	char			**grid;
	int				w;
	int				h;
	t_map			map;
	int				count_steps;
	int				count_collect;
	int				count_exit;
	int				count_player;
	char			*allowed_symbols;
}			t_game;

typedef struct s_flood
{
	char		**map;
	int			cols;
	int			rows;
	int			count_collect;
	int			p_x;
	int			p_y;
	bool		exit_found;
}	t_flood;

void	check_arguments(int ac, char **av, t_game *game);
//int		suffix_check(char *s);
t_game	get_map(char *map);
void	whatsup(int i);
void	check_grid_symbols(t_game *game);
void	check_path(t_game *g, char *input_file);
void	free_flood(t_flood *flood);

#endif