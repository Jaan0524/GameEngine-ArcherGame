#include <SDL.h>
#include <SDL_image.h>
#include "Label.h"
#include "Button.h"
#include <iostream>
#include "Image.h"
#include "Archer.h"
#include "EnterGameButton.h"
#include "ShootButton.h"
#include "Game.h"


using namespace Engine;
using namespace ArcherGame;

	static int GAME_STATE = 0; //0 is for title screen, 1 for game, 2 for end screen

	void init_game() {
		Image* background = Image::get_instance(0, 0, constants::width_of_game, constants::height_of_game, "/images/backgroundTEST.jpg");
		Label* welcome_label = Label::get_instance(constants::width_of_game / 3, 50, 300, 150, "Welcome!", { 250,250,250 });
		//Button* enter_game_button = EnterGameButton::get_instance(welcome_label);
		engine.add(background);
		engine.add(welcome_label);
		//engine.add(enter_game_button);
	}

	int main(int argc, char* argv[]) {
		ArcherGame::Game* game = new ArcherGame::Game();
		game->run();




		return 0;
	}
