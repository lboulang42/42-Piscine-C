/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_main_leo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:00:14 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/21 18:31:59 by lboulang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1,&c,1);
}

int	check_valid_input(char *row1, char *row2)
{
	int	i = 0;
	int	result = 0;

	while(row1[i] && row2[i])
	{
		if(row1[i] > '4' || row1[i] < '1' || row2[i] > '4' || row2[i] < '1' || row1[i] + row2[i] > 101)
			return(1);
		i++;
	}
	return (0); 
}

int	is_valid_line(char	*str)
{
	int	i;
	int	total;
	
	i = 0;
	total = 0;
	while(str[i])
	{
		total = total + str[i];
		i++;
	}
	if(total == 202)
		return(0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*str[] = {"3321" ,"3122","1322","3122"};
	

	if(check_valid_input(str[0], str[1]) == 0 && check_valid_input(str[2], str[3]) == 0) // check si les input sont bon, sinon return
	{		printf("valid inputs");
		//envoyer a resolve;
	
	}

	ft_putchar('\n');
	return	(0);
}







//remplir les colonnes avc entrees 1 et 4 ;
//check si 3 chiffres deja presents dans la grille remplir le 4e (si 4 dans col[0],[2],[3] et row[1,2,3] ajouter 4 dans [1,0])
//faire le tour avec le premier chiffre colle : si 2 : 123 si 3 : 12 EN PRENANT EN COMPTE SI IL EST DANS LA RANGEE
//si 3 donnee sur 4 dans la rangee, remplir le 4e
//
