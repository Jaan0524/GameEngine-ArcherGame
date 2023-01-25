#include "System.h"
#include <iostream>

namespace Engine {
	System::System()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("MyGame", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, constants::width_of_game, constants::height_of_game, 0);
		renderer = SDL_CreateRenderer(window, -1, 0);
		TTF_Init();
		font = TTF_OpenFont((constants::gResPath + "/fonts/ITCKRIST.ttf").c_str(), 30);
		if (!font)
			std::cout << "Could not find Font!";
	}

	System::~System()
	{
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}

	SDL_Renderer* System::get_renderer() const
	{
		return renderer;
	}

	TTF_Font* System::get_font() const
	{
		return font;
	}

System sys;
}