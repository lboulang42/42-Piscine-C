/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:32:42 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/14 18:11:18 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *ptr, int *ptr2)
{
	int	temp;

	temp = *ptr;
	*ptr = *ptr2;
	*ptr2 = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	globali;
	int	i;

	globali = 0;
	while (globali < size)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
			}
			i++;
		}
		globali++;
	}	
}
