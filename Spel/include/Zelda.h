#ifndef ZELDA_H
#define ZELDA_H
#include "JumpingCharacter.h"
#include "Sprite.h"
#include "Arrow.h"
#include "Game.h"
#include "Maths.h"
namespace ArcherGame {
	class Zelda : public Engine::JumpingCharacter
	{
	public:
		static Zelda* get_instance();
		void tick();
		void handle_collision(Sprite* other_collider);
	protected:
		Zelda(int x, int y, int width, int height, std::string image_path, bool is_jumping, bool is_on_ground);
	private:
		bool is_jumping_m;
		bool is_on_ground_m;
		Engine::vector2f velocity_m;
		void jump();
	};
}
#endif