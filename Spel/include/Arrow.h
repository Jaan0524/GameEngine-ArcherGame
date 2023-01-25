#ifndef ARROW_H
#define ARROW_H
#include "Projectile.h"
#include "GameEngine.h"
namespace ArcherGame {
	class Arrow : public Engine::Projectile
	{
	public:
		static Arrow* get_instance();
		void tick();
		void move();
	protected:
		Arrow(int x, int y, int width, int height, std::string image_path);	
	};
}
#endif