#include "Projectile.h"
namespace Engine {
	Projectile::~Projectile() {
		SDL_DestroyTexture(texture_m);
	}
	Projectile::Projectile(int x, int y, int width, int height, std::string image_path) :Sprite{x,y,width,height} {
		SDL_Surface* surface = IMG_Load((constants::gResPath + image_path).c_str());
		texture_m = SDL_CreateTextureFromSurface(Engine::sys.get_renderer(), surface);
		SDL_FreeSurface(surface);
	}
	void Projectile::draw() const {
		SDL_RenderCopy(Engine::sys.get_renderer(), texture_m, NULL, &get_rect());
	}
	Uint32 Projectile::get_pixel(int x, int y)const {
		//SDL_Surface* surface = SDL_CreateRGBSurface(0, rect_m.w, rect_m.h, 32, 0, 0, 0, 0);
		int pitch;
		void* pixels;
		SDL_LockTexture(texture_m, NULL, &pixels, &pitch);
		Uint32* pixels_32 = (Uint32*)pixels;
		Uint32 pixel = pixels_32[(y - rect_m.y) * (pitch / 4) + (x - rect_m.x)];
		SDL_UnlockTexture(texture_m);
		return pixel;
	}

}