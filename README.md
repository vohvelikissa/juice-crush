# juice-crush
candy crush clone with a Juice Leskinen twist

# Why am I doing this?
For fun mostly. This kind of project quite literally cannot be for profit.

# TODO list
- [ ] create/use some kind of datastructure for storing and handling the infinite level/map
- [ ] create a function for initially filling the infinite (in actuality 8x8) map
- [ ] create a function for handling the destruction of the juice candies
- [ ] create a function for handling the refilling of the infinite map
- [ ] find out what is needed to create a window with SDL
- [ ] create a function that updates the candies drawn on the screen based on the grid
- [ ] create a function that handles the mouse clicks on the grid positions
- [ ] create a function that handles the destruction of juice candies based on the clicks
- [ ] play some music in the background with some kind of a function

# Notes

Candygrid.c was chosen as a container for the candygrid operations because <br> I have been sold the idea of splitting code functionalities into files that are named accordingly to what the thing is and what it might do when finished at one point and of course I have full on just purchased it and am currently still running with it. If you are able to code and have the will to modify the structural choices of this project to be something else entirely, feel free to do so! I will not be changing this choice for a while.

The candygrid itself is stored in a 2D char array with the size of 8x8 as per previos text lines of text in this very file and it has been initialized as follows:

```c
char candygrid[8][8]
```
