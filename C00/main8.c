/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:03:42 by macourio          #+#    #+#             */
/*   Updated: 2022/07/07 17:10:44 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_print_combn(int n);

int	main(void)
{
	int	i;

	i = 0;
	while (++i < 9)
	{
		ft_print_combn(i);
		printf("\n\n\n");
	}
}
