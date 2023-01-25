#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <vector>
#include "Sprite.h"
#include <string>
#include <SDL_image.h>
namespace Engine{
	class GameEngine
	{

	public:
		GameEngine();
		void add(Sprite* sprite);
		void remove(Sprite* sprite);
		void run();

	private:
		std::vector<Sprite*> sprites_m, sprites_to_add_m, sprites_to_remove_m;
		Uint32 tick_interval_m;
		bool quit_m;
		void poll_for_event(bool& quit);
		void update_sprites_and_check_for_collisions();
		void add_sprites();
		void remove_sprites();
		void draw_sprites();
	};
	extern GameEngine engine;
}
#endif