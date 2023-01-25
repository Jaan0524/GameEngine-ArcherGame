#include "Link.h"
namespace ArcherGame {
	Link* Link::get_instance(ScoreLabel* score_label) {
		return new Link(50, constants::ground_level, 150, 100, "/images/Link_Archer_Purp.png", constants::link_max_magazine, score_label);
	}
	void Link::shoot_arrow(){
		if (magazine_m > 0) {
			magazine_m--;
			ArcherGame::Arrow* a = Arrow::get_instance();
			Engine::engine.add(a);
			score_label_m->increase_score();
		}
	}
	void Link::tick() {
		if (reload_counter_m % constants::link_reload_counter == 0 && magazine_m < constants::link_max_magazine) { //Link laddar om sitt magazin 1 gång för varje
			magazine_m++;																						   //x link_reload_counter som tick() körs.
		}
		reload_counter_m++;
	}
	Link::Link(int x, int y, int width, int height, std::string image_path, int magazine, ScoreLabel* score_label) :Archer{x,y,width,height,image_path,magazine}, score_label_m(score_label)
	{
	}
}