/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmontcou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 08:32:48 by mmontcou          #+#    #+#             */
/*   Updated: 2022/08/28 16:30:29 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush02.h"

char	*nextline(char *buff, int *index)
{
	int		len;
	char	*out;
	int		i;

	i = -1;
	len = 0;
	if (!buff)
		return (NULL);
	while (buff[*index + len] && buff[*index + len] != '\n')
		len++;
	len = len + 1;
	out = malloc(sizeof(char) * len + 1);
	if (!out)
		return (NULL);
	while (++i < len)
		out[i] = buff[*index + i];
	*index += len;
	return (out);
}

char	**dict_creat(char *buff)
{
	int		i;
	char	**out;
	int		count_line;
	int		index;

	count_line = 0;
	i = -1;
	while (buff[++i])
		if (buff[i] == '\n')
			count_line++;
	out = (char **)malloc(sizeof(char *) * (count_line + 1));
	if (!out)
		return (NULL);
	index = 0;
	i = 0;
	while (i < count_line)
	{
		out[i] = nextline(buff, &index);
		if (!out[i])
			return (free(out), NULL);
		i++;
	}
	return (out);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	buffer[1024];
	char	**dict;
	char	*dict_path;
	char	*number;

	dict_path = "numbers.dict";
	if (argc == 2)
		number = argv[1];
	else if (argc == 3)
	{
		dict_path = argv[1];
		number = argv[2];
	}
	else if (argc != 2 && argc != 3)
		return (0);
	if ((ft_strlen(number) != 1 || number[0] != '0') && chk_input(number) == 0)
		return (0);
	fd = open(dict_path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr("Error"), 0);
	read(fd, buffer, 690);
	close(fd);
	dict = dict_creat(buffer);
	ft_display_number(dict, number);
}
