#include "Arrow.h"
namespace ArcherGame {

	Arrow* Arrow::get_instance() {
		return new Arrow(110,400, 40, 100, "/images/Arrow.png");
	}
	Arrow::Arrow(int x, int y, int width, int height, std::string image_path) :Engine::Projectile(x, y, width, height, image_path)
	{};

	void Arrow::tick() {
		if (this->get_rect().x > constants::width_of_game) { //Om pilens x coordinate har lämnat skärmen för spelet så tas det bort.
			Engine::engine.remove(this);
		}
		else
			move();
	}
	void Arrow::move() {
		for (int i = constants::arrow_velocity; i > 0; i--) {
			rect_m.x += 1;
		}
		 //velocity sätts i headerfilen Constants
	}
}