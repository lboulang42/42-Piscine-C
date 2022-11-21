/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:38:26 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/28 21:38:30 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush02.h"

unsigned int	chk_input(char *str)
{
	if (str[0] == 0 && ft_strlen(str) > 1)
		return (ft_putstr("Error"), 0);
	if (str[0] == '-')
		return (ft_putstr("Error"), 0);
	if (ft_strlen(str) > 11)
		return (ft_putstr("Error"), 0);
	if (ft_atoi_test(str) == 0)
		return (ft_putstr("Error"), 0);
	return (ft_atoi_test(str));
}

unsigned int	ft_atoi_test(char *str)
{
	int				i;
	int				sign;
	int				result;
	unsigned int	rresult;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
				sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] -48;
		i++;
	}
	result = sign * result;
	if (str[i] != '\0' || result < 0)
		return (0);
	else
		return (rresult = result, rresult);
	return (result);
}
