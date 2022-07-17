/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 07:55:06 by macourio          #+#    #+#             */
/*   Updated: 2022/07/13 20:21:46 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		while (str[i] && str[i] != to_find[0])
			i++;
		j = 0;
		while (str[i] == to_find[j] && str[i])
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
		{
			res = &str[i - j];
			return (res);
		}
	}
	return ((void *)0);
}
