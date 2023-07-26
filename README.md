# juice-crush
candy crush clone with a Juice Leskinen twist

# Why am I doing this?
For fun mostly. This kind of project quite literally cannot be for profit.

# TODO list
- [X] create/use some kind of datastructure for storing and handling the infinite level/map
- [X] create a function for initially filling the infinite (in actuality 8x8) map
- [ ] create a function for handling the destruction of the juice candies
- [ ] create a function for handling the refilling of the infinite map
- [ ] find out what is needed to create a window with SDL
- [ ] create a function that updates the candies drawn on the screen based on the grid
- [ ] create a function that handles the mouse clicks on the grid positions
- [ ] create a function that handles the destruction of juice candies based on the clicks
- [ ] play some music in the background with some kind of a function

# Notes

## Code Standard that I attempt to use here
This project will be following GNU C coding standards to the best of my abilities.

## Reasonings for why different files are like they are
Candygrid.c was chosen as a container for the candygrid operations because <br> I have been sold the idea of splitting code functionalities into files that are named accordingly to what the thing is and what it might do when finished at one point and of course I have full on just purchased it and am currently still running with it. If you are able to code and have the will to modify the structural choices of this project to be something else entirely, feel free to do so! I will not be changing this choice for a while.

## Backstories for the significant variables that I just happened to become using
The candygrid itself is stored in a 2D char array with the size of 8x8 as per previos text lines of text in this very file and it has been initialized as follows:

```c
char candygrid_storage_2D_array[8][8];
```

Exactly the same and equivalent variable called destructiongrid_storage_2D_array has been created to be initially empty and then to be a marker for which squares need to be removed and then filled with both gravity magic and regeneration of candies. 

## Reasongings for why the functions are the way that they are

### ft_empty_candy_grid
Created the function ft_empty_candy_grid() to avoid any issues that might at some point come from any data that has been left behind to the 2D array that is candygrid_storage_2D_array. The function and the array are both stored in the candygrid operations c file. The function just goes through every "square" in the "grid" that is the 2D array that was just mentioned in the text before this almost incoherent rambling that I call a README.md and just replaces everything with a ' '.

```c
void ft_empty_candy_grid()
{
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			candygrid_storage_2D_array[i][j] = ' ';
		}
	}
}
```

### ft_fill_empty_candy_grid
Created the function ft_fill_empty_candy_grid() to initialize the game state properly for the game to start without any issues. It first calls ft_empty_candy_grid() and then fills the character positions in exactly the same way as the ft_empty_candy_grid but instead of spaces the characters used are capital letters ranging from A to A+n where n is the maximum number that the randomly assigned variable is allowed to go above A. The method for random number used is rand which is defined in the stdlib.h

```c
'A'+(rand() % n)
```

### Testing functions
For testing purposes functions print_grid_to_console() and printthewholefuckingcombo() were added. print_grid_to_console is there to print the stored grid values to console to see if they work properly and the combo function is there to see if the functions work together well. So far everything has worked better than expected, which itself is not saying much because my code is generally so fucking bad.

