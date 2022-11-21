/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:28:55 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/30 19:28:57 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char	*str);
int	find_index(char c, char *base);
int	ft_get_nb_digits(int nb, int size_base);

int	ft_error(char *base, int base_len)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	if (base_len < 2)
		return (1);
	while (base[i])
	{
		c = base[i];
		j = 1;
		if (c == '+' || c == '-' || (c < 14 && c > 9) || c == ' ')
			return (1);
		while (base[i + j])
		{
			if (base[i + j] == base [i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base_edited(int nb, char *base, char *result, int size)
{
	int				size_base;
	int				i;
	int				k;
	unsigned int	nbri;

	size_base = ft_strlen(base);
	i = 0;
	k = 0;
	nbri = nb;
	if (nb < 0)
	{
		result[0] = '-';
		nbri = -1 * nb;
		k++;
	}
	while (i < size - k)
	{
		result[size - i - 1] = base[nbri % size_base];
		nbri /= size_base;
		i++;
	}
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		nb_base10;
	int		digit_size;
	int		bf_len;
	int		bt_len;

	bf_len = ft_strlen(base_from);
	bt_len = ft_strlen(base_to);
	if (ft_error(base_from, bf_len) != 0 || ft_error(base_to, bt_len) != 0)
		return (NULL);
	nb_base10 = ft_atoi_base(nbr, base_from);
	digit_size = ft_get_nb_digits(nb_base10, ft_strlen(base_to)) + 1;
	if (nb_base10 < 0)
		digit_size = digit_size + 1;
	str = malloc(sizeof(char) * digit_size);
	if (!str)
		return (NULL);
	ft_putnbr_base_edited(nb_base10, base_to, str, digit_size -1);
	str[digit_size - 1] = '\0';
	return (str);
}
