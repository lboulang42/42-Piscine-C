/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:19:30 by lboulang          #+#    #+#             */
/*   Updated: 2022/08/21 18:46:17 by ilouacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	row_check(int limitl, int limitr, int *row)
{
	int	i;
	int	biggestl;
	int	biggestr;
	int	counter_r;
	int	counter_l;
	
	i = 0;
	biggestl = row[0];
	counter_r = 1;
	counter_l = 1;
	biggestr = row[N];
	while(i < 3)
	{
		if(row[i] < row[i + 1] && row[i + 1] > biggest)
		{
			biggestl = row[i];
			counter_l++;
		}
                if(row[3 - i] < row[3 - i - 1] && row[3 - i - 1] > biggest)
		{
			biggestr = row[3 - i - 1];
			counter_r++;
		}
		i++;
	}
	if(counter_l == limitl && counter_r == limitr)
		return(0);
	return(1);
}


int	main()
{
	int	corner1 = 4;
	int	corner2 = 1;
	int	row[] = {1,2,3,4};
	

	printf("%d\n", row_check(corner1, corner2, row));



}
