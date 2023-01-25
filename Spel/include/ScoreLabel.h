#ifndef SCORELABEL_H
#define SCORELABEL_H
#include "Label.h"
namespace ArcherGame {
	class ScoreLabel :public Engine::Label
	{
	public:
		static ScoreLabel* get_instance();
		void increase_score();
		void reset_score();
	protected:
		ScoreLabel(int x, int y, int width, int height, std::string text);
	private:
		int score_m;
	};
}
#endif