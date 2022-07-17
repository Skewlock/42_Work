/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:50:28 by macourio          #+#    #+#             */
/*   Updated: 2022/07/17 15:37:42 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

struct s_board
{
	char	*row_top;
	char	*row_bottom;
	char	*col_left;
	char	*col_right;
	int		**grid;
};

typedef struct s_board	t_board;

int		validate_grid(t_board *board);
int		place_build(t_board *board, int pos);
void	ft_display_grid(t_board *board);

#endif
