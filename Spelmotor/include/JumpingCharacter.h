#ifndef JUMPINGCHARACTER_H
#define JUMPINGCHARACTER_H
#include "Sprite.h"
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Constants.h"
#include "System.h"
#include "GameEngine.h"
#include "Maths.h"
#include "Archer.h"
namespace Engine {
	class JumpingCharacter : public Engine::Sprite
	{
	public:
		~JumpingCharacter();
		void draw() const;
		void key_button_down(const SDL_Event& event, const Uint8* keyPressed);
		Uint32 get_pixel(int x, int y)const;
	protected:
		JumpingCharacter(int x, int y, int width, int height, std::string image_path);
		virtual void jump() = 0;
	private:
		SDL_Texture* texture_m;
	};
}
#endif