/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:01:41 by macourio          #+#    #+#             */
/*   Updated: 2022/07/13 16:50:00 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[++i])
	{
		j = i + 1;
		while ((base[j] != base[i]) && base[j])
			j++;
		if (base[j] != '\0')
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long int	nb;

	if (ft_check_base(base) == 0)
		return ;
	nb = nbr;
	len = ft_strlen(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb < len)
		write(1, &base[nb], 1);
	else
	{
		ft_putnbr_base(nb / len, base);
		ft_putnbr_base(nb % len, base);
	}
}
