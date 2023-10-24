#include <SDL.h>
#include <String.h>

// TODO: remove these
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	// things to do:
	// 1. consume an init file
	//      a. same directory?
	// 2. start game loop
	//      a. game managers?
	// 3. start render loop
	// 4. consume scene file
	// 5. go go go

	BAL::String lmao("this is also a test");
	std::string test("this is a test");
	std::cout << test;
	std::cout << lmao.Data();

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << test;
	return 0;
}
