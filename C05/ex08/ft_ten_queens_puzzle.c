/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:26:22 by macourio          #+#    #+#             */
/*   Updated: 2022/07/17 18:45:16 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_check_board(char *board, int size)
{
	int i;
	int	j;

	i = 0;
	while (board[i] && i < size)
	{
		j = i + 1;
		while (board[j] && j < size)
		{
			if (board[j] == board[i] || board[j] == board[i] + (j - i)
				|| board[j] == board[i] - (j - i))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	place_queen(char *grid, int	queen)
{
	int	value;
	char grid2[11];

	value = 0;
	if (queen == 10)
		return (1);
	/*else if (grid[queen] != '0')
		return place_queen(grid, queen + 1);*/
	while (value < 10)
	{
		ft_strcpy(grid2, grid);
		grid2[queen] = value + 48;
		if (ft_check_board(grid2, queen + 1) == 1)
		{
			grid[queen] = value + 48;
			if (place_queen(grid, queen + 1) == 1)
			{
				return (1);
			}
		}
		value++;
	}
	grid[queen] = '0';
	return (0);
}

char *find_next_solve(char *grid)
{
	int	i;

	i = 9;
	//printf("in %s\n", grid);
	grid[9]++;
	while (grid[i] > '9' && i > 0)
	{
		grid[i] = '0';
		grid[i - 1]++;
		i--;
	}
	//printf("out %s\n", grid);
	return (grid);
}

int	ft_ten_queens_puzzle(void)
{
	char grid[11] = "0000000000";
	char *gridd;
	int	res;
	
	place_queen(grid, 0);
	gridd = find_next_solve(grid);
	while (gridd[0] < '9' && gridd[1] < '7')
	{
		gridd = find_next_solve(gridd);
		res = place_queen(gridd, 0);
		if (res == 1)
			printf("%s\n", gridd);
	}
}

int main()
{
	ft_ten_queens_puzzle();
}
