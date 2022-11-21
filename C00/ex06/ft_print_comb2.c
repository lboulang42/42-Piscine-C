/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 02:18:05 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/13 18:33:09 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char c1, char c2, char c3, char c4)
{
	ft_putchar(c1);
	ft_putchar(c2);
	write(1, " ", 1);
	ft_putchar(c3);
	ft_putchar(c4);
	if (c1 != '9' || c2 != '8' || c3 != c1 || c4 != c1)
		write(1, ", ", 2);
}

void	loop(char c1, char c2, char c3, char c4)
{
	while (c1 <= '9')
	{
		c2 = '0';
		while (c2 <= '9')
		{
			c3 = '0';
			while (c3 <= '9')
			{
				c4 = c2 + 1;
				while (c4 <= '9')
				{
					if (c1 <= c3 && c2 <= c4)
						ft_print(c1, c2, c3, c4);
					c4++;
				}
				c3++;
			}
			c2++;
		}
		c1++;
	}
}

void	ft_print_comb2(void)
{
	char	c1;
	char	c2;
	char	c3;
	char	c4;

	c1 = '0';
	c2 = '0';
	c3 = '0';
	c4 = '0';
	loop(c1, c2, c3, c4);
}
