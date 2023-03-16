/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phelebra <xhelp00@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:12:37 by phelebra          #+#    #+#             */
/*   Updated: 2023/03/16 09:13:07 by phelebra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	whatsup(int i)
{
	if (i == 1)
		ft_printf("Error Message: Map is not right-angled.\n");
	else if (i == 2)
		ft_printf("Error Message: Map has invalid characters.\n");
	else if (i == 3)
		ft_printf("Error Message: Map has no valid path.\n");
	else if (i == 4)
		ft_printf("Error Message: Map is not surrounded by walls.\n");
	else if (i == 5)
		ft_printf("Error Message: Checking in game objects failed.\n");
	exit (0);
}
