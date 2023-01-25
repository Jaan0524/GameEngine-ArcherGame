#ifndef BUTTON_H
#define BUTTON_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include "Sprite.h"
#include "System.h"
namespace Engine {
	class Button: public Sprite
	{
	public:
		static Button* get_instance(int x, int y, int width, int height, std::string text, SDL_Color color, std::string up_icon_path, std::string down_icon_path);
		~Button();
		void draw() const;
		void tick();
		void mouse_button_down(const SDL_Event& event);
		void mouse_button_up(const SDL_Event& event);
		virtual void perform(Button* source);
	protected:
		Button(int x, int y, int width, int height, std::string text, SDL_Color color, std::string up_icon_path, std::string down_icon_path);
	private:
		std::string text_m;
		bool pressed_m;
		SDL_Texture *up_icon_m, *down_icon_m, *texture_m;;
	};
}
#endif