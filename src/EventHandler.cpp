#include <EventHandler.h>

#include <Utils.h>

EventHandler::EventHandler(const map<control, SDLKey> & keyMap, Camera * c1, Camera * c2) :
	_keyMap(keyMap),
	_c1(c1),
	_c2(c2),
	_icam(1)
{

}

bool EventHandler::handleEvent(SDLWindowManager & windowManager, Game & game) {
	bool finish = false;
	bool changeCamera = false;
	SDL_Event event;
	while (windowManager.pollEvent(event)) {
		if (event.type == SDL_QUIT) {
			finish = true;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == _keyMap[control::CHANGE_CAMERA]) {
				changeCamera = true;
			}
		}
	}
	if (finish) {
		return true;
	}
	if (changeCamera) {
		if (_icam == 1) {
			game.getPointOfView().setCamera(_c2);
			_icam = 2;
		} else if (_icam == 2) {
			game.getPointOfView().setCamera(_c1);
			_icam = 1;
		}
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
		if (_icam == 1) {
			_c1->moveFront(1);
		} else if (_icam == 2) {
			_c2->moveFront(1);
		}
	}
	if (windowManager.isKeyPressed(SDLK_n)) { // TODO should not be key
		if (_icam == 1) {
			_c1->moveFront(-1);
		} else if (_icam == 2) {
			_c2->moveFront(-1);
		}
	}
	return false;
}
