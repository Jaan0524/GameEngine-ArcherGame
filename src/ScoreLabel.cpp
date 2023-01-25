#include "ScoreLabel.h"
namespace ArcherGame {
	ScoreLabel* ScoreLabel::get_instance() {
		return new ScoreLabel(650, 75, 150, 100, "0");
	}
	ScoreLabel::ScoreLabel(int x, int y, int width, int height, std::string text):Label(x,y,width,height,text,{250,250,250}), score_m(0) {
	}
	void ScoreLabel::increase_score() {
		score_m++;
		this->set_text(std::to_string(score_m), { 250,250,250 });
	}
	void ScoreLabel::reset_score() {
		score_m = 0;
		this->set_text(std::to_string(score_m), { 250,250,250 });
	}
}