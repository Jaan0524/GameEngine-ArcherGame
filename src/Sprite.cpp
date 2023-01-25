#include "Sprite.h"
namespace Engine {

	Sprite::Sprite(int x, int y, int width, int height) :rect_m{x,y,width,height}, width_m(width), height_m(height) {

	}
	Sprite::~Sprite() {
	}

	const SDL_Rect& Sprite::get_rect() const
	{
		return rect_m;
	}
	const int Sprite::get_width()const {
		return width_m;
	}
	const int Sprite::get_height() const{
		return height_m;
	}
	const Uint32 Sprite::get_pixel(int x, int y)const{
		return 1;
	}
	void Sprite::handle_collision(Sprite* other_collider){
	}
}