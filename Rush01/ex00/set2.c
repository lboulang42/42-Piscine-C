void	setres(int (*tab)[4][4])
{
	int i;
	int j;

	i = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*tab)[i][j] = 0;
			j++;
		}
		i++;
		
	}
	

}