#ifndef ENTERGAMEBUTTON_H
#define ENTERGAMEBUTTON_H
#include "Button.h"
#include "GameEngine.h"
#include "Game.h"
namespace ArcherGame {
	class EnterGameButton : public Engine::Button
	{
	public:
		static EnterGameButton* get_instance() {
			return new EnterGameButton();
		}
	protected:
		EnterGameButton() :Button{400, 400, 200, 100, "Start", { 250,250,250 }, "/images/UpIcon.png", "/images/DownIcon.png" }
		{
		};
		void perform(Button* source);
		
	};

}
#endif