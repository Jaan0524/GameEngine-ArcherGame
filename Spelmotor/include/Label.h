#ifndef LABEL_H
#define LABEL_H
#include "Sprite.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "System.h"
namespace Engine {
	class Label : public Sprite
	{
	public:
		static Label* get_instance(int x, int y, int width, int height, std::string text, SDL_Color color);
		~Label();
		void draw() const;
		void tick();
		void set_text(std::string new_text, SDL_Color color);
		std::string get_text();
	protected:
		Label(int x, int y, int width, int height, std::string text, SDL_Color color);
	private:
		std::string text_m;
		SDL_Texture* texture_m;
	};
}
#endif