#include <Array.h>
#include <FileIo.h>
#include <Pair.h>
#include <SDL.h>
#include <String.h>
#include <xml/XmlParser.h>

// TODO: remove these
#include <iostream>
#include <string>
#include <vector>

// int main(int argc, char* argv[])
int main()
{
	// things to do:
	// 1. consume an init file a. same directory?
	// 2. start game loop
	//      a. game managers?
	// 3. start render loop
	// 4. consume scene file
	// 5. go go go

	// std::vector<BAL::Pair<BAL::String, BAL::String>> test;
	BAL::Array<BAL::Pair<BAL::String, BAL::String>> test2;
	BAL::Pair<BAL::String, BAL::String> mo;
	mo.setFirst("first");
	mo.setSecond("second");
	test2.push_back(mo);

	BAL::String lmao("this is also a test");
	lmao.resize(2);

	lmao += "this is a mega test";
	lmao = "this is also a test";
	lmao.resize(20);
	std::string lmaouchwer = "this is also a test";
	std::string test("this is a test");
	std::cout << test;
	std::cout << lmao.data();
	BAL::FileIo fileHandler;
	BAL::Array<char> fileBuffer;
	BAL::String filePath("Resources/Window.xml");
	fileHandler.openFile(filePath, &fileBuffer);
	BAL::XmlParser parser;
	parser.parseData(fileBuffer);
	// TODO: get the parse data I'm looking for (width and height) then load it into the
	// sdl window

	// TODO:  build some debugging around this
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window =
		SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Delay(3000);

	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << test;
	return 0;
}
