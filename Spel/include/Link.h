#ifndef LINK_H
#define LINK_H
#include "Archer.h"
#include "Arrow.h"
#include "ScoreLabel.h"
namespace ArcherGame {
	class Link : public Engine::Archer
	{
	public:
		static Link* get_instance(ScoreLabel* score_label);
		void shoot_arrow();
		void tick();
	protected:
		Link(int x, int y, int width, int height, std::string image_path, int magazine, ScoreLabel* score_label);
	private:
		ScoreLabel* score_label_m;
	};
}
#endif