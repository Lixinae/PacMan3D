#include <EventHandler.h>

EventHandler::EventHandler(const map<control, SDLKey> &keyMap) : _keyMap(keyMap) {}

EventHandler::State EventHandler::handleBeginTitleEvent(SDLWindowManager &windowManager) {
	SDL_Event event{};
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
	SDL_Event event{};
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
	SDL_Event event{};
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
	cameraMovement(windowManager, game);
	return state;
}

EventHandler::State EventHandler::handleGameEvent(SDLWindowManager &windowManager, Game &game) {
	SDL_Event event{};
	EventHandler::State state = EventHandler::State::CONTINUE;
	while (windowManager.pollEvent(event)) {
		if (event.type == SDL_QUIT) {
			state = EventHandler::State::QUIT;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == _keyMap[control::CHANGE_CAMERA]) {
				game.changeCamera();
			}
			if (event.key.keysym.sym == _keyMap[control::PAUSE_GAME]) {
				state = EventHandler::State::PAUSE;
			}
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
	cameraMovement(windowManager, game);
	return state;
}

EventHandler::State EventHandler::handlePauseMenuEvent(SDLWindowManager &windowManager, Game &game) {
	SDL_Event event{};
	EventHandler::State state = EventHandler::State::CONTINUE;
	while (windowManager.pollEvent(event)) {
		if (event.type == SDL_QUIT) {
			state = EventHandler::State::QUIT;
		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == _keyMap[control::CHANGE_CAMERA]) {
				game.changeCamera();
			}
			if (event.key.keysym.sym == _keyMap[control::PAUSE_GAME]) {
				state = EventHandler::State::NEXT;
			}
			if (event.key.keysym.sym == _keyMap[control::EXIT]) {
				state = EventHandler::State::QUIT;
			}
			if (event.key.keysym.sym == _keyMap[control::SAVE_GAME]) {
				game.toJSONFile(Utils::GAME_SAVE_FILE);
			}
			if (event.key.keysym.sym == _keyMap[control::LOAD_GAME]) {
				game = Game::fromJSONFile(Utils::GAME_SAVE_FILE);
			}
			if (event.key.keysym.sym == _keyMap[control::RESTART]) {
				game.restart();
			}
		}
	}
	cameraMovement(windowManager, game);

	return state;
}

void EventHandler::cameraMovement(const SDLWindowManager &windowManager, Game &game) const {
	if (windowManager.isMouseButtonPressed(SDL_BUTTON_LEFT)) {
		game.moveFrontCamera(1);
	}
	if (windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT)) {
		game.moveFrontCamera(-1);
	}
}
