/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-duc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 12:17:23 by mle-duc           #+#    #+#             */
/*   Updated: 2022/08/14 18:39:28 by mle-duc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	print_walls(int width, char left_corner, char wall, char right_corner)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i == 0)
		{
			ft_putchar(left_corner);
		}
		else
		{
			if (i < width - 1)
			{
				ft_putchar(wall);
			}
			else
			{
				ft_putchar(right_corner);
			}
		}
		i++;
	}
	ft_putchar('\n');
}

void	rush(int width, int length)
{
	int	i;

	i = 0;
	if (width <= 0 || length <= 0)
	{
		return ;
	}
	while (i < length)
	{
		if (i == 0 || i == length - 1)
			print_walls(width, 'o', '-', 'o');
		else
			print_walls(width, '|', ' ', '|');
		i++;
	}
}
