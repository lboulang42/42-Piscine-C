/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:43:28 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/28 02:45:58 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	check_charset(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

char	*tab_fill(int start_i, int end_i, char *str)
{
	int		i;
	char	*result;
	int		index;

	result = malloc(sizeof(char) * ((end_i - start_i) + 1));
	if (!result)
		return (NULL);
	i = 0;
	index = 0;
	while (str[i])
	{
		while (i >= start_i && i <= end_i)
		{
			result[index] = str[i];
			index++;
			i++;
		}
		i++;
	}
	return (result);
}

int	counter(char *str, char *charset)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] && check_charset(str[i], charset) == 1)
			i++;
		if (str[i] == '\0')
			break ;
		while (str[i] && check_charset(str[i], charset) == 0)
			i++;
		counter++;
	}
	return (counter);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		index_tab;
	int		start;

	i = 0;
	index_tab = 0;
	tab = malloc(sizeof(char *) * counter(str, charset) + 1);
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while (str[i] && check_charset(str[i], charset) == 1)
			i++;
		if (str[i] == '\0')
			break ;
		start = i;
		while (str[i] && check_charset(str[i], charset) == 0)
			i++;
		tab[index_tab] = tab_fill(start, i - 1, str);
		index_tab++;
	}
	tab[index_tab] = 0;
	return (tab);
}
