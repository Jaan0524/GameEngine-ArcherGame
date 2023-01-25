#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include "Constants.h"
#include "SDL_ttf.h"

namespace Engine{
class System
	{
	public:
		System();
		~System();
		SDL_Renderer* get_renderer() const;
		TTF_Font* get_font() const;
	
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
};
	extern System sys;
}

#endif