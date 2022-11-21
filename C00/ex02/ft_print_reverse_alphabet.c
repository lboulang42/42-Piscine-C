/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 18:52:00 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/13 17:50:33 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{	
	int		i;
	int		j;
	char	c;

	i = 97;
	j = 122;
	while (j >= i)
	{	
		c = j;
		write(1, &c, 1);
		j--;
	}
}
