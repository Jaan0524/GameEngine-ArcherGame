#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>
#include "System.h"
namespace Engine{

	class Sprite{

	public:
		virtual ~Sprite();
		virtual void draw() const = 0;
		virtual void tick() = 0;
		virtual void handle_collision(Sprite* other_collider);
		virtual void mouse_button_down(const SDL_Event& event){};
		virtual void mouse_button_up(const SDL_Event& event){};
		virtual void key_button_down(const SDL_Event& event, const Uint8* keyPressed){};
		virtual void key_button_up(const SDL_Event& event, const Uint8* keyPressed){};
		const SDL_Rect& get_rect() const;
		const int get_width() const;
		const int get_height() const;
		const Uint32 get_pixel(int x, int y)const; // metod som subklasser kan implementera om dem vill detektera collision på pixelnivå.
	protected:
		Sprite(int x, int y, int width, int height);
		SDL_Rect rect_m;
	private:
		int width_m, height_m;
		const Sprite& operator=(const Sprite&) = delete;
		const Sprite& operator=(Sprite&) = delete;
		Sprite(const Sprite&) = delete;

	};
}
#endif

