/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmontcou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 08:32:48 by mmontcou          #+#    #+#             */
/*   Updated: 2022/08/28 16:30:29 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush02.h"

int	ft_counter(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n < -9 || n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_search_dict(char **dict, char *nb)
{
	char	*index;
	int		i;

	i = 0;
	index = NULL;
	while (dict[i])
	{
		if (ft_strstr(dict[i], nb) != 0)
		{	
			index = ft_strstr(dict[i], nb);
			break ;
		}
		i++;
	}
	return (index);
}

void	ft_display_unit(char **dict, char c, int len)
{
	ft_putstr(ft_search_dict(dict, &c) + len +2);
}

void	ft_display_dict(char **dict, int pow, int len)
{
	ft_putstr(ft_search_dict(dict, ft_itoa(pow)) + len + 2);
	(void)len;
}

void	ft_display_number(char **dict, char *number)
{
	int	size;
	int	pow;

	size = ft_strlen(number);
	pow = ft_recursive_power(10, size - 1);
	if (size == 1)
		ft_display_unit(dict, *number, ft_strlen(number));
	else
	{
		ft_display_dict(dict, pow, ft_strlen(number));
	}
}
