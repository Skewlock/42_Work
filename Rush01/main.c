/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rush01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsammons <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:02:57 by hsammons          #+#    #+#             */
/*   Updated: 2022/07/17 15:40:12 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush01.h"

int	ft_check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 48 && str[i] <= 57)
			&& ((str[i + 1] == 32 && str[i + 2] >= 48 && str[i + 2] <= 57)
				|| (str[i] >= 48 && str[i] <= 57 && str[i + 1] == 0)))
			i += 2;
		else
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

t_board	*create_board(void)
{	
	t_board	*board;

	board = (t_board *)malloc(sizeof(t_board));
	return (board);
}

t_board	*ft_create_data(char *argv[], t_board *board)
{
	int		i;
	char	*temp;

	i = -1;
	temp = (char *)malloc(5 * sizeof(char));
	while (++i < 4)
		temp[i] = argv[1][i * 2];
	board->row_top = temp;
	i = -1;
	temp = (char *)malloc(5 * sizeof(char));
	while (++i < 4)
		temp[i] = argv[1][(i * 2) + 8];
	board->row_bottom = temp;
	i = -1;
	temp = (char *)malloc(5 * sizeof(char));
	while (++i < 4)
		temp[i] = argv[1][(i * 2) + 16];
	board->col_left = temp;
	i = -1;
	temp = (char *)malloc(5 * sizeof(char));
	while (++i < 4)
		temp[i] = argv[1][(i * 2) + 24];
	board->col_right = temp;
	return (board);
}

t_board	*ft_create_grid(t_board *board)
{
	int	**tab;
	int	i;
	int	j;

	tab = (int **)malloc(4 * sizeof(int *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		tab[i] = (int *)malloc(4 * sizeof(int));
		if (!tab[i])
			return (NULL);
		j = -1;
		while (++j < 4)
			tab[i][j] = 0;
		i++;
	}
	board->grid = tab;
	return (board);
}

int	main(int argc, char **argv)
{
	t_board	*board;

	if (argc != 2)
		return (-1);
	if (!ft_check_string(argv[1]))
		return (-1);
	board = create_board();
	board = ft_create_data(argv, board);
	board = ft_create_grid(board);
	place_build(board, 0);
	ft_display_grid(board);
	free(board->grid);
	free(board->row_top);
	free(board->row_bottom);
	free(board->col_left);
	free(board->col_right);
	free(board);
	return (0);
}
