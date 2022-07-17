/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:44:59 by macourio          #+#    #+#             */
/*   Updated: 2022/07/12 11:55:54 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
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
		if (base[i] == ' ' || base[i] == '\t' || base[i] == '\n'
			|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
			return (0);
	}
	return (1);
}

int	ft_is_in_base(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	ft_index_of(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (ft_check_base(base) == 0)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_is_in_base(str[i], base))
	{
		res = res * ft_strlen(base) + ft_index_of(base, str[i]);
		i++;
	}
	return (res * sign);
}
