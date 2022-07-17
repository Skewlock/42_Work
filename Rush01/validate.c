/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 08:54:28 by macourio          #+#    #+#             */
/*   Updated: 2022/07/17 15:38:04 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	validate_col_left(char *line, int **grid)
{
	int	i;
	int	j;
	int	visible;
	int	height;

	j = 0;
	while (j < 4)
	{
		i = 0;
		height = grid[j][0];
		visible = 1;
		while (i < 4)
		{
			if (grid[j][i] > height)
			{
				height = grid[j][i];
				visible++;
			}
			i++;
		}
		if (visible != line[j++] - 48)
			return (0);
	}
	return (1);
}

int	validate_row_top(char *line, int **grid)
{
	int	i;
	int	j;
	int	visible;
	int	height;

	j = 0;
	while (j < 4)
	{
		i = 0;
		height = grid[0][j];
		visible = 1;
		while (i < 4)
		{
			if (grid[i][j] > height)
			{
				height = grid[i][j];
				visible++;
			}
			i++;
		}
		if (visible != line[j++] - 48)
			return (0);
	}
	return (1);
}

int	validate_col_right(char *line, int **grid)
{
	int	i;
	int	j;
	int	visible;
	int	height;

	j = 0;
	while (j < 4)
	{
		i = 0;
		height = grid[j][3];
		visible = 1;
		while (i < 4)
		{
			if (grid[j][4 - i - 1] > height)
			{
				height = grid[j][4 - i - 1];
				visible++;
			}
			i++;
		}
		if (visible != line[j++] - 48)
			return (0);
	}
	return (1);
}

int	validate_row_bottom(char *line, int **grid)
{
	int	i;
	int	j;
	int	visible;
	int	height;

	j = 0;
	while (j < 4)
	{
		i = 0;
		height = grid[3][j];
		visible = 1;
		while (i < 4)
		{
			if (grid[4 - i - 1][j] > height)
			{
				height = grid[4 - i - 1][j];
				visible++;
			}
			i++;
		}
		if (visible != line[j++] - 48)
			return (0);
	}
	return (1);
}

int	validate_grid(t_board *board)
{
	int	valid;
	int	i;
	int	j;

	valid = validate_col_left(board->col_left, board->grid);
	valid += validate_col_right(board->col_right, board->grid);
	valid += validate_row_top(board->row_top, board->grid);
	valid += validate_row_bottom(board->row_bottom, board->grid);
	if (valid != 4)
		return (0);
	i = 1;
	while (++i < 16)
	{
		if (board->grid[i / 4][i % 4] != 0)
		{
			j = (i % 4);
			while (++j < 4)
			{
				if (board->grid[i / 4][i % 4] == board->grid[i / 4][j])
					return (0);
			}
		}
	}
	return (1);
}
