/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:34:03 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/29 21:34:05 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_error(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base_len < 2)
		return (1);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	find_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (ft_error(base, ft_strlen(base)) == 0)
	{	
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		while (str[i] == '-' || str[i] == '+')
		{	
			if (str[i] == '-')
				sign = sign * -1;
			i++;
		}
		while (str[i] && find_index(str[i], base) != -1)
		{
			result = result * ft_strlen(base) + find_index(str[i], base);
			i++;
		}
		result = result * sign;
	}
	return (result);
}

/*int	main(int argc, char **argv)
{
	if (argc == 3)
		printf("%d\n", ft_atoi_base(argv[1], argv[2]));
}*/
