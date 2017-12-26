#include <EventHandler.h>

#include <Utils.h>

EventHandler::EventHandler(const map<control, SDLKey> & keyMap) : _keyMap(keyMap) {

}

bool EventHandler::handleEvent(SDLWindowManager & windowManager, Game & game) {
	SDL_Event event;
	while (windowManager.pollEvent(event)) {
		if (event.type == SDL_QUIT) {
			return true;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == _keyMap[control::CHANGE_CAMERA]) {
				game.changeCamera();
			}
			if (event.key.keysym.sym == _keyMap[control::UP]){
				game.orientPacman(Utils::Orientation::NORTH);
			}
			if (event.key.keysym.sym ==_keyMap[control::DOWN]){
				game.orientPacman(Utils::Orientation::SOUTH);
			}
			if (event.key.keysym.sym == _keyMap[control::LEFT]){
				game.orientPacman(Utils::Orientation::WEST);
			}
			if (event.key.keysym.sym == _keyMap[control::RIGHT]){
				game.orientPacman(Utils::Orientation::EAST);
			}
		}
	}
	if (windowManager.isKeyPressed(SDLK_b)) { // TODO should not be key
		game.moveFrontCamera(1);
	}
	if (windowManager.isKeyPressed(SDLK_n)) {
		game.moveFrontCamera(-1);
	}
	return false;
}
