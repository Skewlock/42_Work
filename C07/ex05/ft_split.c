/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macourio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 07:27:38 by macourio          #+#    #+#             */
/*   Updated: 2022/07/20 11:04:00 by macourio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_letters(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_in_charset(str[i], charset))
		i++;
	return (i);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_in_charset(str[i], charset))
			i++;
		count++;
		i += ft_count_letters(&str[i], charset);
	}
	return (count);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && i < n)
		i++;
	res = (char *)malloc((i + 1) * sizeof(char));
	i = -1;
	while (str[++i] && i < n)
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		size;
	char	**res;

	i = 0;
	j = 0;
	size = ft_count_words(str, charset);
	if (size > 0)
		res = (char **)malloc((size + 1) * sizeof(char *));
	if (size == 0)
		res = (char **)malloc(1 * sizeof(char));
	if (!res)
		return (NULL);
	while (i < size)
	{
		while (str[j] && ft_is_in_charset(str[j], charset))
			j++;
		res[i] = ft_strndup(&str[j], ft_count_letters(&str[j], charset));
		j += ft_count_letters(&str[j], charset);
		i++;
	}
	res[i] = 0;
	return (res);
}
