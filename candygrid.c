#include<stdlib.h>

char candygrid_storage_2D_array[8][8];

void 
ft_empty_candy_grid() 
{
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j<8; j++)
		{
			candygrid_storage_2D_array[i][j] = ' ';
		}
	}
}

void
ft_fill_empty_candy_grid(int n)
{
	ft_empty_candy_grid();
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j<8; j++)
		{
			candygrid_storage_2D_array[i][j] = 'A'+(rand() % n);
		}
	}
}
