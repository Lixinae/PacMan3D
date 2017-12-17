#include <EventHandler.h>

#include <Utils.h>

EventHandler::EventHandler(const map<control, SDLKey> & keyMap) : _keyMap(keyMap) {

}

bool EventHandler::handleEvent(SDLWindowManager & windowManager, Game & game) {
	bool changeCamera = false;
	SDL_Event event{};
	while (windowManager.pollEvent(event)) {
		if (event.type == SDL_QUIT) {
			return true;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == _keyMap[control::CHANGE_CAMERA]) {
				changeCamera = true;
			}
		}
	}
	if (changeCamera) {
		game.getPointOfView()->setNextCamera();
	}
	if (windowManager.isKeyPressed(_keyMap[control::UP])) {
		game.orientPacman(Utils::Orientation::NORTH);
	}
	if (windowManager.isKeyPressed(_keyMap[control::DOWN])) {
		game.orientPacman(Utils::Orientation::SOUTH);
	}
	if (windowManager.isKeyPressed(_keyMap[control::LEFT])) {
		game.orientPacman(Utils::Orientation::WEST);
	}
	if (windowManager.isKeyPressed(_keyMap[control::RIGHT])) {
		game.orientPacman(Utils::Orientation::EAST);
	}
	if (windowManager.isKeyPressed(SDLK_b)) { // TODO should not be key
		game.getPointOfView()->getCurrentCamera().moveFront(1);
	}
	if (windowManager.isKeyPressed(SDLK_n)) { // TODO should not be key
		game.getPointOfView()->getCurrentCamera().moveFront(-1);
	}
	return false;
}
