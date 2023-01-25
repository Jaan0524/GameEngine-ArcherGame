#include "GameEngine.h"
#include <SDL.h>
#include "System.h"
#include "Constants.h"
#include "Maths.h"
#include "Game.h"
namespace Engine {
	GameEngine::GameEngine() :tick_interval_m(constants::number_of_ticks / constants::FPS), quit_m(false) {

	}

	void GameEngine::add(Sprite* sprite)
	{
		sprites_to_add_m.push_back(sprite);
	}

	void GameEngine::remove(Sprite* sprite)
	{
		sprites_to_remove_m.push_back(sprite);
	}

	void GameEngine::poll_for_event(bool& quit) { //sätter quit variabeln till true om SQL_quit
		SDL_Event event;
		const Uint8* currentKeyboardState;

		while (SDL_PollEvent(&event)) {

			currentKeyboardState = SDL_GetKeyboardState(NULL);
			switch (event.type) {

			case SDL_QUIT: quit = true; break;
			case SDL_MOUSEBUTTONDOWN:
				for (Sprite* s : sprites_m) {
					s->mouse_button_down(event);
				}
				break;
			case SDL_MOUSEBUTTONUP:
				for (Sprite* s : sprites_m) {
					s->mouse_button_up(event);
				}
				break;
			case SDL_KEYDOWN:
				for (Sprite* s : sprites_m) {
					s->key_button_down(event, currentKeyboardState);
				}
				break;
			case SDL_KEYUP:
				for (Sprite* s : sprites_m) {
					s->key_button_up(event, currentKeyboardState);
				}
				break;
			} //switch
		}//inner while
	}

	void GameEngine::update_sprites_and_check_for_collisions() {
		for (Sprite* sprite : sprites_m) { //tick loop that updates state of all sprites each time in the loop and checks for collision
			sprite->tick();
			for (Sprite* s : sprites_m) {
				if (Maths::check_collission_two_sprites_pixel(sprite, s))
					sprite->handle_collision(s);
			}
		}
	}

	void GameEngine::add_sprites() {
		for (Sprite* sprite : sprites_to_add_m) // Loop that goes through the "buffer" of sprites to ADD and adds them.
			sprites_m.push_back(sprite);
		sprites_to_add_m.clear();
	}

	void GameEngine::remove_sprites() {
		for (Sprite* sprite : sprites_to_remove_m) { //Loop that goes through the "buffer" of sprite to REMOVE and removes them.
			for (std::vector<Sprite*>::iterator iterator = sprites_m.begin(); iterator != sprites_m.end();) {
				if (*iterator == sprite) {
					iterator = sprites_m.erase(iterator);
					delete(sprite);
				}
				else
					iterator++;
			}
		}
		sprites_to_remove_m.clear();
	}

	void GameEngine::draw_sprites() {
		SDL_RenderClear(sys.get_renderer());
		for (Sprite* s : sprites_m) { //Ritar ut sprites i nytt tillstånd.
			s->draw();
		}
		SDL_RenderPresent(sys.get_renderer());
	}

	void GameEngine::run() //Huvudmetoden som innehåller allting.
	{
		while (!quit_m) {
			Uint32 next_tick = SDL_GetTicks() + tick_interval_m;

			poll_for_event(quit_m);

			update_sprites_and_check_for_collisions();
			
			add_sprites();

			remove_sprites();

			ArcherGame::game.update();

			draw_sprites();

			int delay = next_tick - SDL_GetTicks();

			if (delay > 0)
				SDL_Delay(delay);

		}//outer while (game loop)
	}

	GameEngine engine;
}