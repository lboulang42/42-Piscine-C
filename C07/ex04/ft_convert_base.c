/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:29:01 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/30 19:29:03 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_nb_digits(int nb, int size_base)
{
	int	pow;

	pow = 1;
	while (nb / size_base != 0)
	{
		nb /= size_base;
		pow += 1;
	}
	return (pow);
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
