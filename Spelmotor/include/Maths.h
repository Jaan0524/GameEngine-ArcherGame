#ifndef MATHS_H
#define MATHS_H
#include "Sprite.h"
#include <vector>
#include "SDL.h"
#include <iostream>
namespace Engine {
	class vector2f {
	public:
		vector2f():_x(0), _y(0) {}
		vector2f(float x, float y) :_x(x), _y(y) {
		}
		float _x, _y;
	};
	class Maths
	{
	public:
		static bool check_collision_two_sprites_rect(Engine::Sprite* s1, Engine::Sprite* s2) {
			int s1_top, s2_top;
			int s1_bottom, s2_bottom;
			int s1_left, s2_left;
			int s1_right, s2_right;
			s1_top = s1->get_rect().y;
			s1_bottom = s1->get_rect().y + s1->get_height();
			s1_left = s1->get_rect().x;
			s1_right = s1->get_rect().x + s1->get_width();
			s2_top = s2->get_rect().y;
			s2_bottom = s2->get_rect().y + s2->get_height();
			s2_left = s2->get_rect().x;
			s2_right = s2->get_rect().x + s2->get_width();
			//If any of the sides from A are outside of B
			if (s1_bottom <= s2_top)
			{
				return false;
			}

			if (s1_top >= s2_bottom)
			{
				return false;
			}

			if (s1_right <= s2_left)
			{
				return false;
			}

			if (s1_left >= s2_right)
			{
				return false;
			}

			//If none of the sides from A are outside B
			return true;
		}
		static bool check_collission_two_sprites_pixel(Engine::Sprite* s1, Engine::Sprite* s2) {

			//Om det finns en rektangel mellan dem två spritesen så har dem med säkerhet inte kolliderat.
			if (!SDL_HasIntersection(&s1->get_rect(), &s2->get_rect())) {
				return false;
			}

			//Hämta rektangeln som överlappar mellan dem 2 sprites.
			SDL_Rect intersection;
			SDL_IntersectRect(&s1->get_rect(), &s2->get_rect(), &intersection);

			//loopa igenom dem 2 pixlar från vardera sprite som överlappar varandra
			for (int y = intersection.y; y < intersection.y + intersection.h; y++) {
				for (int x = intersection.x; x < intersection.x + intersection.h; x++) {

					//hämta pixeldata för dem 2 spritesen på den nuvarande kordinatens position och spara dem i variabler
					Uint32 pixel1 = s1->get_pixel(x, y);
					Uint32 pixel2 = s2->get_pixel(x, y);
					//Maskar bort allt förutom Alpha värdet i pixeldatan
					pixel1 &= 255;
					pixel2 &= 255;
					//Om alpha värdet i pixeldatan inte var 0 på bägge
					if(pixel1 != 0 && pixel2 != 0)
						return true;
				}
			}
			return false;
		}
		static vector2f start_jump(vector2f velocity, float jump_speed) {
			velocity._y = -jump_speed;
			return velocity;
		}
		static vector2f apply_gravity(vector2f velocity, float gravity) {
			velocity._y += gravity;
			return velocity;
		}
	};
}
#endif