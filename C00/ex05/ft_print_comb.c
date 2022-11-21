/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 02:18:05 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/13 18:09:37 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	while (c1 <= '7')
	{	
		c2 = c1 + 1;
		while (c2 <= '8')
		{	
			c3 = c2 + 1;
			while (c3 <= '9')
			{	
				ft_putchar(c1);
				ft_putchar(c2);
				ft_putchar(c3);
				if (c1 != '7' || c2 != '8' || c3 != '9')
					write(1, ", ", 2);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
