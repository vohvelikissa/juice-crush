#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char candygrid_storage_2D_array[8][8];
char destructiongrid_storage_2D_array[8][8];

void
print_grid_to_console() {
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			printf(" (%c, %c) ",candygrid_storage_2D_array[i][j],destructiongrid_storage_2D_array[i][j]);
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
			destructiongrid_storage_2D_array[i][j] = ' ';
		}
	}
}

void
ft_fill_empty_candy_grid(int n)
{
	//ft_empty_candy_grid(); not auto emptying because I have a better idea now.
	for (int i = 0; i<8; i++)
	{
		for (int j = 0; j<8; j++)
		{
			if(candygrid_storage_2D_array[i][j] == ' ') {
				candygrid_storage_2D_array[i][j] = 'A'+(rand() % n);
			}
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

int 
count_forward_in_x(int x, int y) {
	int count = 0;
	for (int i = x; i < 8; i++) {
		if (candygrid_storage_2D_array[y][i] == candygrid_storage_2D_array[y][x]) {	
			destructiongrid_storage_2D_array[y][i] = 'X';
			count++;
		} else {
			return count;
		}
	}
	return count;
}

int
count_backward_in_x(int x, int y) {
	int count = 0;
	for (int i = x; i >= 0; i--) {
		if (candygrid_storage_2D_array[y][i] == candygrid_storage_2D_array[y][x]) {
			destructiongrid_storage_2D_array[y][i] = 'X';
			count++;
		} else {
			return count;
		}
	}
	return count;
}

int 
count_from_x(int x, int y) {
	return count_backward_in_x(x,y)+count_forward_in_x(x,y);
}

int count_backward_in_y(int x, int y) {
	int count = 0;
	for (int i = y; i >= 0; i--) {
		if (candygrid_storage_2D_array[i][x] == candygrid_storage_2D_array[y][x]) {
			destructiongrid_storage_2D_array[i][x] = 'X';
			count++;
		} else {
			return count;
		}
	}
	return count;
}

int count_forward_in_y(int x, int y) {
	int count = 0;
	for (int i = y; i < 8; i++) {
		if (candygrid_storage_2D_array[i][x] == candygrid_storage_2D_array[y][x]) {
			destructiongrid_storage_2D_array[i][x] = 'X';
			count++;
		} else {
			return count;
		}
	}
	return count;
}

int 
count_from_y(int x, int y) {
	return count_backward_in_y(x,y)+count_forward_in_y(x,y);
}

int
detect_if_candy_can_be_destroyed(int x, int y) {
	/**
	the reason for why the number is six is that the
	number of candies to qualify for destruction is 3
	and my dumbass made one of the candies to be counted 4 times.
	**/
	return (count_from_x(x,y)+count_from_y(x,y)) >= 6;
}

void destroy_the_allowed_candies() {
	for (int i = 0; i<8; i++) {
		for (int j = 0; j<8; j++) {
			if (destructiongrid_storage_2D_array[i][j] == 'X') {
				candygrid_storage_2D_array[i][j] = ' ';
				destructiongrid_storage_2D_array[i][j] = ' ';
			}
		}
	}
}

//TODO: apply "gravity" to fill holes
//TODO: destroy the destroyable inbetweeners

void
printthewholefuckingcombo() {
	//TODO: test the destruction functionality here
	ft_empty_candy_grid();
	ft_fill_empty_candy_grid(5);
	print_grid_to_console();
	detect_if_candy_can_be_destroyed(2,1);
	print_grid_to_console();
	destroy_the_allowed_candies();
	print_grid_to_console();
	ft_fill_empty_candy_grid(5);
	print_grid_to_console();
}
