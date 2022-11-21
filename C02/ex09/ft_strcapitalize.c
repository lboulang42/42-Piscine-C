/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:20:20 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/20 20:43:48 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	int	result;

	result = 1;
	if (c > 96 && c < 123)
		result = 0;
	return (result);
}

int	is_alphanumeric(char c)
{
	int	result;

	result = 0;
	if (c > 47 && c < 58)
		result = 1;
	if (c > 64 && c < 91)
		result = 1;
	if (c > 96 && c < 123)
		result = 1;
	return (result);
}

char	*ft_strlowcase(char *str)
{
	int		i;
	char	temp;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
		{
			temp = str[i] + 32;
			str[i] = temp;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i - 1]) == 0 && is_lowercase(str[i]) == 0)
				str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
