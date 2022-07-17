/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 07:44:11 by macourio          #+#    #+#             */
/*   Updated: 2022/07/10 07:50:37 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_first_line(int f)
{
	int	i;

	i = 0;
	while (i < f)
	{
		if (i == 0)
			ft_putchar('A');
		if (i > 1 && i < f)
			ft_putchar('B');
		if (i == f -1 && f > 1)
			ft_putchar('C');
		i++;
	}
	ft_putchar('\n');
}

void	ft_middle_line(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == x - 1)
		{
			ft_putchar('B');
			ft_putchar('\n');
		}
		else if (i == 0)
			ft_putchar('B');
		else
			ft_putchar(' ');
		i++;
	}
}

void	ft_last_line(int f)
{
	int	i;

	i = 0;
	while (i < f)
	{
		if (i == 0)
			ft_putchar('C');
		if (i > 1 && i < f)
			ft_putchar('B');
		if (i == f -1 && f > 1)
			ft_putchar('A');
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 1;
	if (x <= 0 || y <= 0)
		return ;
	ft_first_line(x);
	while (i < y - 1)
	{
		ft_middle_line(x);
		i++;
	}
	if (y > 1)
		ft_last_line(x);
}
