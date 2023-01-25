#include "RestartGameButton.h"
namespace ArcherGame {
	void RestartGameButton::perform(Button* source) {
		game.set_gamestate(1);
	}
}