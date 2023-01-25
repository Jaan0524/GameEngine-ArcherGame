#ifndef IMAGE_H
#define IMAGE_H
#include "Sprite.h"
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "System.h"
namespace Engine {
	class Image : public Sprite
	{
	public:
		static Image* get_instance(int x, int y, int width, int height, std::string path);
		~Image();
		void draw() const;
		void tick();
	protected:
		Image(int x, int y, int width, int height, std::string path);
	private:
		SDL_Texture* texture_m;

	};
}
#endif