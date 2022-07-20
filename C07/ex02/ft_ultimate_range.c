/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:19:08 by macourio          #+#    #+#             */
/*   Updated: 2022/07/18 16:52:22 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	*range = (int *)malloc(((max - min) + 1) * sizeof(int));
	if (!*range)
		return (-1);
	while (i + min < max)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
