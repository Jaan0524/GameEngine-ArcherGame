#include "Archer.h"
namespace Engine {

	Archer::~Archer() {
		SDL_DestroyTexture(texture_m);
	}

	Archer::Archer(int x, int y, int width, int height, std::string image_path, int magazine) :Sprite(x,y,width,height ), magazine_m(magazine), reload_counter_m(0)
	{
		
		SDL_Surface* surface = IMG_Load((constants::gResPath + image_path).c_str());
		Uint32 colorKey = SDL_MapRGB(surface->format, 128, 0, 128);
		SDL_SetColorKey(surface, SDL_TRUE, colorKey);
		texture_m = SDL_CreateTextureFromSurface(Engine::sys.get_renderer(), surface);
		SDL_FreeSurface(surface);
	}	
	
	void Archer::draw() const { 
		SDL_RenderCopy(Engine::sys.get_renderer(), texture_m, NULL, &get_rect());
	}

	int Archer::get_magazine() {
		return magazine_m;
	}

}