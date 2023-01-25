#include "ShootButton.h"
#include <iostream>
namespace ArcherGame {
	void ShootButton::perform(Button* source) {
		archer_m->shoot_arrow();
	}
}