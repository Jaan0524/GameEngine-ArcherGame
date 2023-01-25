#ifndef ARCHER_H
#define ARCHER_H
#include "Sprite.h"
#include "System.h"
#include "SDL.h"
#include "SDL_image.h"
#include <string>
namespace Engine {
	class Archer : public Engine::Sprite
	{
	public:
		~Archer();
		void draw() const;
		virtual void shoot_arrow() = 0;
		int get_magazine();
	protected:
		int magazine_m;
		int reload_counter_m;
		Archer(int x, int y, int width, int height, std::string image_path, int magazine);

	private:
		SDL_Texture* texture_m;

	};
}
#endif // !ARCHER_H