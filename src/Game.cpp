#include "Game.h"
namespace ArcherGame {
	using namespace Engine;
	using namespace ArcherGame;
	Game::Game():gamestate_m(0), state_playing_m(0), background(NULL), welcome_label(NULL), enter_game_button(NULL),
	shoot_button(NULL), score_text(NULL), score(NULL), magazine_label(NULL), zelda(NULL), link(NULL), gameover_label(NULL), restart_game_button(0) {
		
	}
	void Game::update() {
		switch (gamestate_m) { 
		case 0:
			intro_state(); break;
		case 1:
			main_game_state(); break;

		case 2:
			end_game_state(); break;
		default: break;
		}
	}
	void Game::intro_state() {

		if (state_playing_m != 1) {
			background = Image::get_instance(0, 0, constants::width_of_game, constants::height_of_game, "/images/background.jpg");
			welcome_label = Label::get_instance(333, 50, 300, 150, "Welcome!", { 250,250,250 });
			enter_game_button = EnterGameButton::get_instance();
			engine.add(background);
			engine.add(welcome_label);
			engine.add(enter_game_button);
			state_playing_m = 1;
		}
	}
	void Game::main_game_state() {
		if (state_playing_m == 3) {
			Engine::engine.remove(gameover_label);
			Engine::engine.remove(restart_game_button);
			Engine::engine.remove(score);
			Engine::engine.remove(score_text);
		}
		if (state_playing_m != 2) {
			engine.remove(welcome_label);
			engine.remove(enter_game_button);
			score_text = Engine::Label::get_instance(333, 50, 300, 150, "Score:", { 250,250,250 });
			score = ScoreLabel::get_instance();
			link = Link::get_instance(score);
			zelda = Zelda::get_instance();
			magazine_label = MagazineLabel::get_instance(link);
			shoot_button = ShootButton::get_instance(link);
			Engine::engine.add(score_text);
			Engine::engine.add(link);
			Engine::engine.add(score);
			Engine::engine.add(magazine_label);
			Engine::engine.add(shoot_button);
			Engine::engine.add(zelda);
			state_playing_m = 2;
		}
	}
	void Game::end_game_state() {
		if (state_playing_m != 3) {
			gameover_label = Engine::Label::get_instance(285, 200, 400, 300, "GAME OVER", { 0,0,0 });
			restart_game_button = RestartGameButton::get_instance();
			Engine::engine.remove(link);
			score_text->set_text("FINAL SCORE:", { 250,250,250 });
			Engine::engine.remove(magazine_label);
			Engine::engine.remove(shoot_button);
			Engine::engine.remove(zelda);
			Engine::engine.add(gameover_label);
			Engine::engine.add(restart_game_button);
			state_playing_m = 3;
		}
	}
	void Game::run() {
		Engine::engine.run();
	}
	int Game::get_gamestate() {
		return gamestate_m;
	}
	void Game::set_gamestate(int gamestate) {
		gamestate_m = gamestate;
	}
	Game game;
}