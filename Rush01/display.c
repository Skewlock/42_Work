/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Skyscrappers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacourt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 00:28:24 by blacourt          #+#    #+#             */
/*   Updated: 2022/07/17 15:36:34 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "rush01.h"

void	ft_display_grid(t_board *board)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			nb = board->grid[j][i] + 48;
			write(1, &nb, 1);
			if (i < 4 - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			i++;
		}
		i = 0;
		j++;
	}
}
