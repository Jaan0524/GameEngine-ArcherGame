#ifndef MAGAZINELABEL_H
#define MAGAZINELABEL_H
#include "Label.h"
#include "Link.h"
#include "ShootButton.h"
namespace ArcherGame {
	class MagazineLabel : public Engine::Label
	{
	public:
		static MagazineLabel* get_instance(Engine::Archer* link);
		void tick();
	protected:
		MagazineLabel(int x, int y, int width, int height, std::string text, Engine::Archer* archer);
	private:
		Engine::Archer* my_owner_m;
	};
}
#endif