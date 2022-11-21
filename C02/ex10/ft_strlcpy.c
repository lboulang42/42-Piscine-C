/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:20:47 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/23 03:50:22 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (size != 0 && i < size -1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[i] = 0;
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}
