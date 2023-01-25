#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Sprite.h"
#include "SDL_image.h"
namespace Engine {
	class Projectile : public Sprite
	{
	public:
		~Projectile();
		void draw() const;
		virtual void move() = 0;
		Uint32 get_pixel(int x, int y)const;
	protected:
		Projectile(int x, int y, int width, int height, std::string image_path);
	private:
		SDL_Texture* texture_m;

	};
}
#endif