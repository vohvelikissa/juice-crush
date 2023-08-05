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
			destructiongrid_storage_2D_array[i][j] = ' ';
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

int 
count_forward_in_x(int x, int y) {
	int count = 0;
	for (int i = x; i < 8; i++) {
		if (candygrid_storage_2D_array[y][i] == candygrid_storage_2D_array[y][x]) {	
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

//TODO: check which candies can be destroyed
void
fill_the_destroyable_candies_to_the_destroygrid(int x, int y) {
	//TODO: find the dimensions of the destroyable area
	//TODO: find the inbetween areas that can be destroyed
	//TODO: fill the array respectively to the above things
	if (detect_if_candy_can_be_destroyed(x,y)) {
		printf("TO BE IMPLEMENTED\n");
	}
}

//TODO: destroy the allowed candies
//TODO: apply "gravity" to fill holes
//TODO: fill remaining holes with random candies

void
printthewholefuckingcombo() {
	//TODO: test the destruction functionality here
}

int main(void) {
	printthewholefuckingcombo();
}
