#include <EventHandler.h>

EventHandler::EventHandler(const map<control, SDLKey> & keyMap) : _keyMap(keyMap) {

}

EventHandler EventHandler::fromConfiguration(const Configuration & configuration) {
	return EventHandler(configuration.getControlMap());
}

void EventHandler::handleEvent(SDLWindowManager & windowManager, Game & game) {
	Pacman &pacman = game.getPacman();
	if (windowManager.isKeyPressed(_keyMap[control::UP])) {
		pacman.setOrientation(Pacman::Orientation::NORTH);
	}
	if (windowManager.isKeyPressed(_keyMap[control::DOWN])) {
		pacman.setOrientation(Pacman::Orientation::SOUTH);
	}
	if (windowManager.isKeyPressed(_keyMap[control::LEFT])) {
		pacman.setOrientation(Pacman::Orientation::WEST);
	}
	if (windowManager.isKeyPressed(_keyMap[control::RIGHT])) {
		pacman.setOrientation(Pacman::Orientation::EAST);
	}
}
