#ifndef SHOOTBUTTON_H
#define SHOOTBUTTON_H
#include "Button.h"
#include "Label.h"
#include "Archer.h"
#include "MagazineLabel.h"
namespace ArcherGame {
	class ShootButton : public Engine::Button
	{
	public:
		static ShootButton* get_instance(Engine::Archer* archer) {
			return new ShootButton(50, 320, 100, 50, "Shoot", "/images/UpIcon.png", "/images/DownIcon.png", archer);
		}
		void perform(Button* source);
	protected:
		ShootButton(int x, int y, int width, int height, std::string text, std::string up_icon_path, std::string down_icon_path,
			Engine::Archer* archer) :Button{ x,y,width,height,text,{250,250,250}, up_icon_path, down_icon_path }, archer_m(archer)
		{
		};
	private:
		Engine::Archer* archer_m;
	};
}
#endif