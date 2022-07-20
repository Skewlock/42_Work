/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 08:02:36 by macourio          #+#    #+#             */
/*   Updated: 2022/07/20 11:24:59 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int nb, char *base);

int	ft_is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] == ' ' || base[i] == '\n' || base[i] == '\t'
			|| base[i] == '\f' || base[i] == '\v' || base[i] == '\r')
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
	}
	return (1);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (nbr[i] == ' ' || nbr[i] == '\n' || nbr[i] == '\t' || nbr[i] == '\f'
		|| nbr[i] == '\v' || nbr[i] == '\r')
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
		if (nbr[i++])
			sign = -sign;
	while (ft_is_in_base(nbr[i], base) != -1 && nbr[i])
		res = (res * ft_strlen(base)) + ft_is_in_base(nbr[i++], base);
	return (res * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	mid_num;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	mid_num = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(mid_num, base_to));
}
