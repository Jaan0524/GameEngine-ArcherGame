#include "Zelda.h"
namespace ArcherGame {
	Zelda* Zelda::get_instance() {
		return new Zelda(800, constants::ground_level, 100, 100, "/images/Princess_Zelda_Purp.png", false, true);
	}
	Zelda::Zelda(int x, int y, int width, int height, std::string image_path, bool is_jumping, bool is_on_ground)
		: JumpingCharacter{x,y,width,height,image_path}, is_jumping_m(is_jumping), is_on_ground_m(is_on_ground) {
		velocity_m = Engine::vector2f(0.0, 0.0);
	}
	void Zelda::tick(){
		velocity_m = Engine::Maths::apply_gravity(velocity_m, constants::gravity);
		rect_m.y += (int)velocity_m._y;

		if (rect_m.y > constants::ground_level) {
			rect_m.y = constants::ground_level;
			velocity_m._y = 0;
			is_jumping_m = false;
			is_on_ground_m = true;
		}

	}
	void Zelda::handle_collision(Sprite* other_collider) {
		if (this != other_collider) {
			if (Arrow* a = dynamic_cast<Arrow*>(other_collider)) { //check if other_collider is of type Arrow*
				Engine::engine.remove(a);
				ArcherGame::game.set_gamestate(2);
			}
		}
	}
	void Zelda::jump() {
		if (!is_jumping_m && is_on_ground_m) {
			velocity_m = Engine::Maths::start_jump(velocity_m, constants::initial_jump_velocity);
			is_jumping_m = true;
			is_on_ground_m = false;
		}	
	}
}