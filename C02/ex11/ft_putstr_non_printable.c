/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:52:57 by macourio          #+#    #+#             */
/*   Updated: 2022/07/10 19:32:42 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hexa(char c)
{	
	char	hex[2];

	hex[0] = (c & 0xf0) >> 4;
	hex[1] = c & 0x0f;
	if (hex[0] > 9)
		hex[0] += 'a' - 10;
	else
		hex[0] += '0';
	if (hex[1] > 9)
		hex[1] += 'a' - 10;
	else
		hex[1] += '0';
	write(1, "\\", 1);
	write(1, hex, 2);
}

int	ft_is_printable(char c)
{
	if (c < 32)
		return (0);
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_printable(str[i]))
			write(1, &str[i], 1);
		else
			ft_print_hexa(str[i]);
		i++;
	}
}
