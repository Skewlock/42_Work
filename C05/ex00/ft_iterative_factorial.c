/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:11:27 by macourio          #+#    #+#             */
/*   Updated: 2022/07/12 15:31:55 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	res;

	n = 1;
	res = 1;
	if (nb < 0)
		return (0);
	while (n <= nb)
	{
		res = res * n;
		n++;
	}
	return (res);
}
