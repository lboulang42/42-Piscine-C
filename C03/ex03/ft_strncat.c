/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:43:15 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/23 05:53:48 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				idest;
	unsigned int	i;

	idest = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i] != '\0')
	{	
		dest[idest + i] = src[i];
		i++;
	}
	dest[idest + i] = '\0';
	return (dest);
}
