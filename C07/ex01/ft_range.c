/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 08:06:19 by macourio          #+#    #+#             */
/*   Updated: 2022/07/18 08:15:41 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*res;

	if (min >= max)
		return (NULL);
	res = (int *)malloc(((max - min) + 1) * sizeof(int));
	i = 0;
	while (i + min < max)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
