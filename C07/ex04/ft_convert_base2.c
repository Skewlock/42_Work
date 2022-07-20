/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 08:01:53 by macourio          #+#    #+#             */
/*   Updated: 2022/07/20 10:14:34 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_is_in_base(char c, char *base);

char	*ft_strrev(char	*str)
{
	int		i;
	int		size;
	char	temp;

	i = 0;
	size = ft_strlen(str);
	while (i < (size / 2))
	{
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
		i++;
	}
	return (str);
}

int	calculate_length(int nb, char *base)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(base);
	while (nb > size)
	{
		nb /= size;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int nb, char *base)
{
	int		len;
	int		i;
	int		size;
	char	*res;

	i = 0;
	size = ft_strlen(base);
	len = calculate_length(nb, base);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (nb > size)
	{
		res[i] = base[nb % size];
		nb /= size;
		i++;
	}
	res[i++] = base[nb];
	res[i] = '\0';
	return (ft_strrev(res));
}
