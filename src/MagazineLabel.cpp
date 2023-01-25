#include "MagazineLabel.h"
namespace ArcherGame {
	MagazineLabel* MagazineLabel::get_instance(Engine::Archer* link) {
		return new MagazineLabel(link->get_rect().x + 40, link->get_rect().y - 40, 50, 50, std::to_string(constants::link_max_magazine), link);
	}

	MagazineLabel::MagazineLabel(int x, int y, int width, int height, std::string text, Engine::Archer* archer) :
		Label{ x,y,width,height,text, {0,0,0} }, my_owner_m(archer)
	{}

	void MagazineLabel::tick() {
		this->set_text(std::to_string(my_owner_m->get_magazine()), {0,0,0});
	}
}