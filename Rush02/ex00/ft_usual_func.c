/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usual_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:44:13 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/28 21:44:16 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush02.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		write(1, &str[i], 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *dest, char *to_find)
{
	int	i;
	int	j;
	int	q;

	if (!(ft_strlen(to_find)))
		return (dest);
	i = 0;
	q = ft_strlen(to_find);
	while (dest[i])
	{
		j = 0;
		while (dest[i + j] == to_find[j])
		{
			j++;
			if (j == q)
				return (dest + i);
		}
		i++;
	}
	return (0);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	index;
	long	nbr;

	index = ft_counter(n);
	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	res = malloc(sizeof(char) * (index + 1));
	if (!res)
		return (NULL);
	res[index--] = 0;
	while (index > 0)
	{
		res[index--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		res[0] = '-';
	else
		res[0] = nbr + '0';
	return (res);
}
