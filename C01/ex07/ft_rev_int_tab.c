/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 03:30:39 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/14 16:37:27 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	sizevar;

	i = 0;
	temp = 0;
	sizevar = size;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[sizevar -1];
		tab[sizevar - 1] = temp;
		sizevar--;
		i++;
	}
}
