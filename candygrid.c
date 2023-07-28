#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char candygrid_storage_2D_array[8][8];
char desctructiongrid_storage_2D_array[8][8];

void
print_grid_to_console() {
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			printf("%c",candygrid_storage_2D_array[i][j]);
		}
		printf("\n");
	}
}

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

void
move_candy_from_a_to_b(int x1, int y1, int x2, int y2) {
	if ((x1 >= 0 && x1 < 8) && (y1 >= 0 && y1 < 8) && (x2 >= 0 && x2 < 8) && (y2 >= 0 && y2 < 8))
	{
		char destcpy = candygrid_storage_2D_array[y1][x1];
		candygrid_storage_2D_array[y1][x1] = candygrid_storage_2D_array[y2][x2];
		candygrid_storage_2D_array[y2][x2] = destcpy; 
	}
}

void
printthewholefuckingcombo() {
	ft_empty_candy_grid();
	print_grid_to_console();
	ft_fill_empty_candy_grid(5);
	print_grid_to_console();
}


