/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 23:05:43 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/28 00:23:00 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
		i++;
	}
	if (s1[i] == '\0' && s1[i] != s2[i])
	{
		result = s1[i] - s2[i];
	}
	return (result);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_print(char **argv, char *skip)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != skip)
		{
			ft_putstr(argv[i]);
			ft_putchar('\n');
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;	
	char	*skip;

	i = 0;
	skip = argv[0];
	while (i < argc - 1)
	{
		j = 0;
		while (j < argc -1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) >= 0)
			{
				temp = argv[j + 1];
				argv[j + 1] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
	ft_print(argv, skip);
}
