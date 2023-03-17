/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:12:37 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/17 15:26:07 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	whatsup(int i)
{
	if (i == 1)
		ft_printf("ERROR\nMessage: Map is not right-angled.\n");
	else if (i == 2)
		ft_printf("ERROR\nMessage: Map has invalid characters.\n");
	else if (i == 3)
		ft_printf("ERROR\nMessage: Map has no valid path.\n");
	else if (i == 4)
		ft_printf("ERROR\nMessage: Map is not surrounded by walls.\n");
	else if (i == 5)
		ft_printf("ERROR\nMessage: Checking in game objects failed.\n");
	exit (0);
}
