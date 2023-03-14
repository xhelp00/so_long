/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:18:14 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/14 16:53:05 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "libft.h"
# include <sys/errno.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*game_ptr;
	char	*mapArg;
	int		w;
	int		h;
}			t_game;

void	check_arguments(int ac, char **av, t_game *game);
int		suffix_check(char *s);

#endif