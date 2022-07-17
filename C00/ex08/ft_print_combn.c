/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 08:41:38 by macourio          #+#    #+#             */
/*   Updated: 2022/07/07 13:36:41 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_end(int n, int tab[])
{
	int	temp;
	int	i;

	temp = 10;
	i = n;
	while (--i >= 0)
	{
		if (!(tab[i] == temp - 1))
			return (0);
		temp = tab[i];
	}
	return (1);
}

void	ft_display_combn(int n, int tab[])
{
	int	i;
	int	temp;

	i = -1;
	while (++i < n)
	{
		temp = tab[i] + 48;
		write(1, &temp, 1);
	}
	if (ft_check_end(n, tab) == 0)
		write(1, ", ", 2);
}

int	ft_dont_regress(int n, int tab[])
{
	int	i;

	i = n;
	tab[n - 1]--;
	while (--i > 0)
	{
		if (tab[i - 1] < tab[i] - 1)
			return (i - 1);
	}
	return (0);
}

void	ft_print_combn(int n)
{
	int	tab[9];
	int	i;

	i = -1;
	while (++i < 9)
		tab[i] = i;
	ft_display_combn(n, tab);
	while (ft_check_end(n, tab) == 0)
	{
		tab[n - 1]++;
		if (tab[n - 1] > 9)
		{
			i = ft_dont_regress(n, tab);
			tab[i]++;
			while (++i < n)
				tab[i] = tab[i - 1] + 1;
		}
		ft_display_combn(n, tab);
	}
}
