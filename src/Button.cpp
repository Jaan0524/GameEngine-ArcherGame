#include "Button.h"
namespace Engine {
	Button* Button::get_instance(int x, int y, int width, int height, std::string text, SDL_Color color, std::string up_icon_path, std::string down_icon_path)
	{
		return new Button(x, y, width, height, text, color, up_icon_path, down_icon_path); //Filväg vid instansiering av Button sker vid call på get_instance eller 
																							//definieras i egen subklass. T.ex EnterGameButton.
	}

	Engine::Button::~Button()
	{
		SDL_DestroyTexture(texture_m);
		SDL_DestroyTexture(up_icon_m);
		SDL_DestroyTexture(down_icon_m);
	}

	void Engine::Button::draw() const
	{
		if (pressed_m) {
			SDL_RenderCopy(sys.get_renderer(), down_icon_m, NULL, &get_rect());
		}
		else {
			SDL_RenderCopy(sys.get_renderer(), up_icon_m, NULL, &get_rect());
		}
		SDL_RenderCopy(sys.get_renderer(), texture_m, NULL, &get_rect());
	}

	void Engine::Button::tick()
	{
	}

	void Button::mouse_button_down(const SDL_Event& event)
	{
		SDL_Point point = { event.button.x, event.button.y };
		if(SDL_PointInRect(&point, &get_rect()))
			pressed_m = true;
	}

	void Button::mouse_button_up(const SDL_Event& event)
	{
		SDL_Point point = { event.button.x, event.button.y };
		if (SDL_PointInRect(&point, &get_rect()) && pressed_m)
			perform(this);
		pressed_m = false;
	}

	void Button::perform(Button* source)
	{
	}

	Engine::Button::Button(int x, int y, int width, int height, std::string text,SDL_Color color, std::string up_icon_path, std::string down_icon_path):Sprite(x,y,width,height), text_m(text), pressed_m(false)
	{
		SDL_Surface* surface = TTF_RenderText_Solid(sys.get_font(), text_m.c_str(), color);
		texture_m = SDL_CreateTextureFromSurface(sys.get_renderer(), surface);
		SDL_FreeSurface(surface);
		up_icon_m = IMG_LoadTexture(sys.get_renderer(), (constants::gResPath + up_icon_path).c_str());
		down_icon_m = IMG_LoadTexture(sys.get_renderer(), (constants::gResPath + down_icon_path).c_str());

	}
}