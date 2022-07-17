/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:19:40 by macourio          #+#    #+#             */
/*   Updated: 2022/07/17 15:38:18 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdlib.h>

int	**copy_board(t_board *b)
{
	int	i;
	int	j;
	int	**temp;

	i = 0;
	temp = (int **)malloc(4 * sizeof(int *));
	while (i < 4)
	{
		temp[i] = (int *)malloc(4 * sizeof(int));
		j = 0;
		while (j < 4)
		{
			temp[i][j] = b->grid[i][j];
			j++;
		}
		i++;
	}
	return (temp);
}

int	place_build(t_board *board, int pos)
{
	int	i;
	int	**new_board;
	int	**temp;

	if (pos == 16)
		return (1);
	if (board->grid[pos % 4][pos / 4] != 0)
		place_build(board, pos + 1);
	i = 0;
	while (++i < 5)
	{
		new_board = copy_board(board);
		temp = board->grid;
		new_board[pos % 4][pos / 4] = i;
		board->grid = new_board;
		if (validate_grid(board) == 1)
		{
			free(temp);
			if (place_build(board, pos + 1) == 1)
				return (1);
		}
	}
	board->grid = temp;
	return (0);
}
