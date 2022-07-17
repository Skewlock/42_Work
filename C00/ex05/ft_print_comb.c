/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 07:31:07 by macourio          #+#    #+#             */
/*   Updated: 2022/07/06 18:56:29 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_display_comb(int i, int j, int k)
{
	i += 48;
	j += 48;
	k += 48;
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (!(i == 55 && j == 56 && k == 57))
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 2;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				ft_display_comb(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
