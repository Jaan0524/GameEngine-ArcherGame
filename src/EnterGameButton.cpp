#include "EnterGameButton.h"
namespace ArcherGame {

	void EnterGameButton::perform(Button* source) {
		ArcherGame::game.set_gamestate(1);
	}
}