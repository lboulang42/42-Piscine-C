/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:24:35 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/28 21:32:38 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_recursive_power(int nb, int power);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
unsigned int	chk_input(char *str);
unsigned int	ft_atoi_test(char *str);
char			*nextline(char *buff, int *index);
char			**dict_creat(char *buff);
void			ft_display_unit(char **dict, char c, int len);
void			ft_display_num(char **dict, int pow, int len);
void			ft_display_number(char **dict, char *number);
char			*ft_strstr(char *dest, char *to_find);
int				ft_counter(int n);
char			*ft_itoa(int n);

#endif
