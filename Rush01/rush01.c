/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilouacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:12:23 by ilouacha          #+#    #+#             */
/*   Updated: 2022/08/21 23:08:35 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define N 4


// Fonction d'affichage
void	affichage (int tab[N][N])
{
	int	i;
	int	j;

	i = 0;
    	while (i < N)
    	{
		j = 0;
        	while (j < N)
        	{
            		write(1, &tab[i][j], 1);
			j++;
        	}
		i++;
        	write(1, "\n", 1);
            	//write(1, "------------------", 18);
    	}
    	//write(1, "\n\n", 2);
}

void    set(char *str, int (*tab)[N][N])
{
        int i = 0;
        int j = 0;
        int k = 0;

        while(str[i])
        {
                if (i != 0 && i%8 == 0)
                {
                        // printf("%i\n",i);
                        k++;
                        j = 0;
                }
                if (str[i] >= '0' && str[i] <= '9')
                {
                        (*tab)[k][j] = str[i] - '0';
                        j++;
                }
                i ++;
        }
}


// Verifie si k est present ou pas sur la licensesgne
int	absent_ligne (int k, int tab[N][N], int i)
{
	int	j;

	j = 0;
    	while (j < N)
	{
        	if (tab[i][j] == k)
            		return (0);
		j++;
	}
    	return 1;
}

// Verifie si k est present ou pas sur la colonne
int	absent_colonne (int k, int tab[N][N], int j)
{
	int	i;

	i = 0;
    	while (i < N)
	{
        	if (tab[i][j] == k)
            		return (0);
		j++;
	}
	return 1;
}

// Verifier si la solution est  compatible avec les entrees
/*int	is_verified(int tab[N][N], int position, char str)
{


}*/

//Permet de verifier ce qui est dans la position est compatile avec les entrees ou pas
int	est_valide (int tab[N][N], int position)
{
	int	i;
	int	j;
	int	k;
	if (position == N * N)
	{
		//tester la validite de la solution
		//
	
		// Affichage de la table
		affichage(tab);
        	return 1;
	}
	i = position / N;
	j = position % N;
	if (tab[i][j] != 0)
        	est_valide(tab, position + 1);
	k = 1;
	printf(" i = %d, j = %d \n", i, j);
	while (k <= N)
    	{
		if (absent_ligne(k, tab, i) && absent_colonne(k, tab, j))
		{
			tab[i][j] = k;
			printf(" i = %d, j = %d k = %d\n", i, j, k);
			if ( est_valide (tab, position + 1) )
				printf("ca a marche ici : %d, %d\n",k,tab[i][j]);
				//	return 1;
		}
		printf(" i = %d, j = %d , k = %d, tab = %d\n", i, j, k, tab[i][j]);
		k++;
	}
	tab[i][j] = 0;
	return (0);
}

void	init_tab(int tab[N][N], int str[N][N])
{
	int	i = 0, j;
	int r = 0;

	while (r < N * N)
	{
		tab[r / N][r % N] = 0;
		r++;
	}
			
	while (i < N)
	{
		j = 0;
		while (j < N)
		{   
			//tab[i][j] = 0;
			if (str[2][i] == N)
				tab[i][j] = j + 1;
			if (str[2][i] == 1) 
				tab[i][0] = N;
			if (str[3][i] == N)
				tab[i][N - 1 - j] = j + 1;
			if (str[3][i] == 1)
				tab[i][N - 1] = N;
			if (str[0][i] == N)
				tab[j][i] = j + 1;
			if (str[0][i] == 1)
				tab[0][i] = N;
			if (str[1][i] == N)
				tab[N - 1 - j][i] = j + 1;
			if (str[1][i] == 1)
				tab[N - 1][i] = N;
			printf("= %d, j = %d , tab = %d\n", i, j, tab[i][j]);
			j++;
		}
		i++;
	}
}
int main (int argc, char **argv)
{
	(void)	argc;
	(void)	argv;

	int	str[N][N];
	int	tab[N][N];//malloc(sizeof(char) * 4 * 6 * 4 ); // tab[6][6][4];
	
	if (argc != 2)
	{
		write(1, "Error", 5);
		return (0);
	}
	// nettoyage de la chaine a l'entree et conversion en int sous str_int 4*4
	set (argv[1], &str);
//	printf("%d %d\n", str[1][1], str[1][2]);
	// Remplissage des cases evidentes
	init_tab(tab, str);
	//for (int i = 0, i < N, i++)
	//printf("%d%d%d%d\n", tab[0][0], tab[1][0], tab[2][0], tab[3][0]);
	// Fonction recursive
    	est_valide(tab, 0);
	
	// Affichage de la table
    	//affichage(tab);
}
