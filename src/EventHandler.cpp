#include <EventHandler.h>

EventHandler::EventHandler(const Configuration & configuration) 
{

}


void EventHandler::handleEvent(SDLWindowManager & windowManager, Game & game) {
	Pacman &pacman = game.getPacman();
	if (windowManager.isKeyPressed(SDLK_z)) {
		pacman.setOrientation(Pacman::Orientation::NORTH);
	}
	if (windowManager.isKeyPressed(SDLK_s)) {
		pacman.setOrientation(Pacman::Orientation::SOUTH);
	}
	if (windowManager.isKeyPressed(SDLK_q)) {
		pacman.setOrientation(Pacman::Orientation::WEST);
	}
	if (windowManager.isKeyPressed(SDLK_d)) {
		pacman.setOrientation(Pacman::Orientation::EAST);
	}
}
