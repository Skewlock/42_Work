/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:16:02 by macourio          #+#    #+#             */
/*   Updated: 2022/07/20 16:38:35 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;
	t_stock_str	*tab;

	i = 0;
	tab = (t_stock_str *)malloc(ac * sizeof(t_stock_str));
	if (!tab)
		return (NULL);
	while (i < argc)
	{
		tab[i] = (t_stock_str)malloc()
	}
}
