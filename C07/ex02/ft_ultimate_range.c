/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 02:36:10 by lboulang          #+#    #+#             */
/*   Updated: 2022/09/01 18:08:22 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	len;

	i = 0;
	len = max - min;
	if (min >= max)
		return (0);
	range[0] = malloc(sizeof(int) * len);
	if (!range[0])
		return (-1);
	while (i < len)
	{
		range[0][i] = min;
		min ++;
		i++;
	}
	return (i);
}
