/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:05:59 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/16 09:04:44 by phelebra         ###   ########.fr       */
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

void	check_arguments(int ac, char **av, t_game *game)
{
	if (ac > 2)
	{
		ft_printf("Error Message: Too many arguments.\n");
		exit(0);
	}
	else if (ac == 1)
	{
		ft_printf("Error Message: Too few arguments.\n");
		exit(0);
	}
	else if (suffix_check(av[1]) == 0)
	{
		ft_printf("Error Message: Map file has to be .ber format.\n");
		exit(0);
	}
	game->map_arg = av[1];
}
