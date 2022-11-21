/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:59:57 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/22 18:05:28 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	i_tf;
	int	i_str;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		i_tf = 0;
		i_str = i;
		while (str[i_str] == to_find[i_tf])
		{
			if (to_find[i_tf +1] == '\0')
			{
				return (str + i);
			}
			i_tf++;
			i_str++;
		}
		i++;
	}
	return (0);
}
