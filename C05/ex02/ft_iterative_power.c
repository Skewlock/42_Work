/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:35:04 by macourio          #+#    #+#             */
/*   Updated: 2022/07/13 09:37:10 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int res;

	if (power == 0)
		return (1);
	i = 0;
	res = nb;
	while (i < power - 1)
	{
		res *= nb;
		i++;
	}

	return (res);
}
