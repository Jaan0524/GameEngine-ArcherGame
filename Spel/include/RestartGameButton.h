#ifndef RESTARTGAMEBUTTON_H
#define RESTARTGAMEBUTTON_H
#include "Button.h"
#include "GameEngine.h"
#include "Game.h"
namespace ArcherGame {
	class RestartGameButton : public Engine::Button
	{
	public:
		static RestartGameButton* get_instance() {
			return new RestartGameButton();
		}
	protected:
		RestartGameButton() :Button{ 400, 500, 200, 100, "Restart", { 250,250,250 }, "/images/UpIcon.png", "/images/DownIcon.png" }
		{
		};
		void perform(Button* source);

	};

}
#endif