/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:53:20 by macourio          #+#    #+#             */
/*   Updated: 2022/07/20 11:25:49 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *res, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (res[i])
		i++;
	j = 0;
	while (str[j])
	{
		res[i] = str[j];
		i++;
		j++;
	}
	res[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;

	if (size < 1)
	{
		res = (char *)malloc(1 * sizeof(char));
		res[0] = '\0';
		return (res);
	}
	res = malloc(((size + (size - 1) * ft_strlen(sep)) + 1) * sizeof(char));
	res[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		ft_strcat(res, sep);
		i++;
	}
	return (res);
}
