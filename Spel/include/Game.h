#ifndef GAME_H
#define GAME_H
#include "GameEngine.h"
#include "Button.h"
#include "EnterGameButton.h"
#include "RestartGameButton.h"
#include "Image.h"
#include "Label.h"
#include "ScoreLabel.h"
#include "MagazineLabel.h"
#include "JumpingCharacter.h"
#include "Zelda.h"
namespace ArcherGame {
	class Game {
	public:
		Game();
		void run();
		int get_gamestate();
		void set_gamestate(int gamestate);
		void update();
		void intro_state();
		void main_game_state();
		void end_game_state();
	private:
		int gamestate_m; //0 �r f�r intro-sidan. 1 �r f�r huvud-spelet, 2 �r f�r slutsk�rmen.
		int state_playing_m; //Denna variabel �r f�r att kontrollera om spelet redan �r i det �nskade "gamestate" eller inte. S� att inte metoden tillh�rande 
		                     //det statet ska k�ras flera g�nger.
		Engine::Image* background;
		Engine::Label* welcome_label;
		Engine::Label* gameover_label;
		Engine::Button* enter_game_button;
		Engine::Button* restart_game_button;
		Engine::Button* shoot_button;
		Engine::Label* score_text;
		ScoreLabel* score;
		MagazineLabel* magazine_label;
		Engine::JumpingCharacter* zelda;
		Engine::Archer* link;
	};
	extern Game game;
}
#endif