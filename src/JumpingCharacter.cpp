#include "JumpingCharacter.h"

namespace Engine {
	JumpingCharacter::~JumpingCharacter() {
		SDL_DestroyTexture(texture_m);
	}
	void JumpingCharacter::draw() const{
		SDL_RenderCopy(Engine::sys.get_renderer(), texture_m, NULL, &get_rect());
	}

	void JumpingCharacter::key_button_down(const SDL_Event& event, const Uint8* key_pressed){
		if (key_pressed[SDL_SCANCODE_SPACE])
			jump();
	}

	Uint32 JumpingCharacter::get_pixel(int x, int y)const {
		//SDL_Surface* surface = SDL_CreateRGBSurface(0, rect_m.w, rect_m.h, 32, 0, 0, 0, 0);
		int pitch;
		void* pixels;
		SDL_LockTexture(texture_m, NULL, &pixels, &pitch);
		Uint32* pixels_32 = (Uint32*)pixels;
		Uint32 pixel = pixels_32[(y - rect_m.y) * (pitch / 4) + (x - rect_m.x)];
		SDL_UnlockTexture(texture_m);
		return pixel;
	}

	JumpingCharacter::JumpingCharacter(int x, int y, int width, int height, std::string image_path) :Sprite{ x,y,width,height }
	{
		SDL_Surface* surface = IMG_Load((constants::gResPath + image_path).c_str());
		Uint32 colorKey = SDL_MapRGB(surface->format, 128, 0, 128);
		SDL_SetColorKey(surface, SDL_TRUE, colorKey);
		texture_m = SDL_CreateTextureFromSurface(Engine::sys.get_renderer(), surface);
		SDL_FreeSurface(surface);
	}

}