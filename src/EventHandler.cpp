#include <EventHandler.h>

EventHandler::EventHandler(const map<control, SDLKey> &keyMap) : _keyMap(keyMap) {

}

EventHandler::State EventHandler::handleBeginTitleEvent(SDLWindowManager &windowManager) {
	SDL_Event event;
	EventHandler::State state = EventHandler::State::CONTINUE;
	while (windowManager.pollEvent(event)) {
		if (event.type == SDL_QUIT) {
			state = EventHandler::State::QUIT;
		}
		if (event.type == SDL_KEYDOWN) {
			state = EventHandler::State::NEXT;
		}
	}
	return state;
}

EventHandler::State EventHandler::handleEndTitleEvent(SDLWindowManager &windowManager) {
	SDL_Event event;
	EventHandler::State state = EventHandler::State::CONTINUE;
	while (windowManager.pollEvent(event)) {
		if (event.type == SDL_QUIT) {
			state = EventHandler::State::QUIT;
		}
		if (event.type == SDL_KEYDOWN) {
			state = EventHandler::State::NEXT;
		}
	}
	return state;
}

EventHandler::State EventHandler::handleBeginGameEvent(SDLWindowManager &windowManager, Game &game) {
	SDL_Event event;
	EventHandler::State state = EventHandler::State::CONTINUE;
	while (windowManager.pollEvent(event)) {
		if (event.type == SDL_QUIT) {
			state = EventHandler::State::QUIT;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_RETURN) {
				state = EventHandler::State::NEXT;
			}
			if (event.key.keysym.sym == _keyMap[control::CHANGE_CAMERA]) {
				game.changeCamera();
			}
		}
	}
	if (windowManager.isKeyPressed(SDLK_b)) { // TODO should not be key
		game.moveFrontCamera(1);
	}
	if (windowManager.isKeyPressed(SDLK_n)) {
		game.moveFrontCamera(-1);
	}
	return state;
}

EventHandler::State EventHandler::handleGameEvent(SDLWindowManager &windowManager, Game &game) {
	SDL_Event event;
	EventHandler::State state = EventHandler::State::CONTINUE;
	while (windowManager.pollEvent(event)) {
		if (event.type == SDL_QUIT) {
			state = EventHandler::State::QUIT;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == _keyMap[control::CHANGE_CAMERA]) {
				game.changeCamera();
			}
			if (event.key.keysym.sym == _keyMap[control::UP]) {
				game.orientPacman(Utils::Orientation::NORTH);
			}
			if (event.key.keysym.sym == _keyMap[control::DOWN]) {
				game.orientPacman(Utils::Orientation::SOUTH);
			}
			if (event.key.keysym.sym == _keyMap[control::LEFT]) {
				game.orientPacman(Utils::Orientation::WEST);
			}
			if (event.key.keysym.sym == _keyMap[control::RIGHT]) {
				game.orientPacman(Utils::Orientation::EAST);
			}
			//TODO pause
		}
	}
	if (windowManager.isKeyPressed(SDLK_b)) { // TODO should not be key
		game.moveFrontCamera(1);
	}
	if (windowManager.isKeyPressed(SDLK_n)) {
		game.moveFrontCamera(-1);
	}
	return state;
}
