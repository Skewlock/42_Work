/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:47:16 by macourio          #+#    #+#             */
/*   Updated: 2022/07/10 19:33:04 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hexa(char c)
{
	char	hex[2];

	hex[0] = (c & 0xf0) >> 4;
	hex[1] = c & 0x0f;
	if (hex[0] > 9)
		hex[0] += 87;
	else
		hex[0] += 48;
	if (hex[1] > 9)
		hex[1] += 87;
	else
		hex[1] += 48;
	write(1, hex, 2);
}

void	ft_print_first_column(void *addr)
{
	char	*adr;
	int		i;

	i = 7;
	adr = (char *)&addr;
	while (i >= 0)
		ft_print_hexa(adr[i--]);
	write(1, ": ", 2);
}

void	ft_print_mid_column(void *addr, int size)
{
	char	*curr;
	int		i;

	i = 0;
	while (i < size)
	{
		curr = (char *)addr + i;
		ft_print_hexa(*curr);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	if (size < 16)
	{
		while (i++ < 16)
		{
			write(1, "  ", 2);
			if (i % 2 == 0)
				write(1, " ", 1);
		}
	}
}

void	ft_print_last_column(void *addr, int size)
{
	char	*curr;
	int		i;

	i = 0;
	while (i < size)
	{
		curr = (char *)addr + i;
		if (*curr < 32 || *curr == 127)
			write(1, ".", 1);
		else
			write(1, curr, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;

	if (size <= 0)
		return ;
	i = size;
	while (i > 16)
	{
		ft_print_first_column(addr);
		ft_print_mid_column(addr, 16);
		ft_print_last_column(addr, 16);
		addr += 16;
		i -= 16;
	}
	ft_print_first_column(addr);
	ft_print_mid_column(addr, i);
	ft_print_last_column(addr, i);
}
