#include<SDL2/SDL.h>

int main(void)  {
	SDL_Window * gayemscren = SDL_CreateWindow("Juice crush", 600, 1000, 
						600, 1000, SDL_WINDOW_FULLSCREEN);
	SDL_Renderer * gayemren = SDL_CreateRenderer(gayemscren,
						-1, SDL_RENDERER_TARGETTEXTURE);
	//TODO: figure out if you need surface and get it if need be
	//TODO: add tasks
	//TODO: draw candies
	//TODO: register mouse clicks
	//TODO: check if candies can be destroyed based on the last two clicks
	//TODO: refresh screen
	//TODO: draw a click marker
	//TODO: destroy candies accordingly
	//TODO: game loop
}
