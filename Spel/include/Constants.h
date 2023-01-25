#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>
namespace constants {

	//gResPath inneh�ller s�kv�g till resources mappen i datorn.
	const std::string gResPath = "C:/Users/Jacob/Dropbox/My PC (LAPTOP-O70743SV)/Desktop/CPROG/Project/Project/resources";
	const int FPS = 60;
	const int number_of_ticks = 1000; //antal ticks som ska divideras med FPS f�r kontroll av hastighet p� spelet
	const int width_of_game = 1000; //antal pixlar (bredd)
	const int height_of_game = 600; //antal pixlar (h�jd)
	const int ground_level = 410; // y v�rdet f�r niv�n p� marken i spelet.
	const float initial_jump_velocity = 35.0; //hastigheten p� hoppet
	const float gravity = 1.5; //graviteten p� hoppet.
	const int link_max_magazine = 3; //max antal pilar som skytten kan ha i sitt magazine
	const int link_reload_counter = 100; //antal varv av tick() innan omladdning(+1)
	const int arrow_velocity = 10; //hastigheten p� projektilen som f�rdas l�ngst sk�rmen.
}
#endif