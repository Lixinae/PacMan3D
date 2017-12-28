#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <json/json.hpp>
#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>
#include <Game.h>
#include <Renderer.h>
#include <Renderer3D.h>
#include <EventHandler.h>


using namespace glimac;
using namespace std;
using namespace glm;

void waitFrameRate() {
	this_thread::sleep_for(chrono::milliseconds(66));
}

void play(Game &game, SDLWindowManager &windowManager, Renderer &renderer, EventHandler &eventHandler, map<control, SDLKey> keyMap) {
	EventHandler::State state;
	state = EventHandler::State::CONTINUE;
	while (state == EventHandler::State::CONTINUE) {
		state = eventHandler.handleBeginTitleEvent(windowManager);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderer.renderBeginTitle();
		windowManager.swapBuffers();
	}
	if (state == EventHandler::State::QUIT) {
		return;
	}
	while (!game.isFinish()) {
		state = EventHandler::State::CONTINUE;
		while (state == EventHandler::State::CONTINUE) {
			state = eventHandler.handleBeginGameEvent(windowManager, game);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			renderer.renderGame(game.getRepresentation(), game.getInformations());
			renderer.renderBeginGame();
			windowManager.swapBuffers();
			waitFrameRate();
		}
		if (state == EventHandler::State::QUIT) {
			return;
		}
		while (game.iterate()) {
			state = eventHandler.handleGameEvent(windowManager, game);
			if (state == EventHandler::State::QUIT) {
				return;
			}
			if (state == EventHandler::State::PAUSE) {
				state = EventHandler::State::CONTINUE;
				while (state == EventHandler::State::CONTINUE) {
					state = eventHandler.handlePauseMenuEvent(windowManager, game);
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
					renderer.renderGame(game.getRepresentation(), game.getInformations());
					renderer.renderPauseMenu(keyMap);
					windowManager.swapBuffers();
					waitFrameRate();
				}
				if (state == EventHandler::State::QUIT) {
					return;
				}
			}
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			renderer.renderGame(game.getRepresentation(), game.getInformations());
			windowManager.swapBuffers();
			waitFrameRate();
		}
		game.reset();
	}
	state = EventHandler::State::CONTINUE;
	while (state == EventHandler::State::CONTINUE) {
		state = eventHandler.handleEndTitleEvent(windowManager);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderer.renderEndTitle();
		windowManager.swapBuffers();
	}

}

int realMain() {

	int windowWidth = 800;
	int windowHeight = 600;

	SDLWindowManager windowManager(windowWidth, windowHeight, "Pacman3D");

	GLenum glewInitError = glewInit();
	if (GLEW_OK != glewInitError) {
		cerr << glewGetErrorString(glewInitError) << endl;
		return EXIT_FAILURE;
	}

	srand(time(nullptr));

	glEnable(GL_DEPTH_TEST);

	Configuration configuration = Configuration::fromJSONFile("assets/configurations/configuration.json");

	Game game = Game::fromJSONFile("assets/games/gameRealBoard.json");

	EventHandler eventHandler(configuration.getControlMap());

	Renderer *renderer = new Renderer3D(windowWidth, windowHeight, game.getPointOfView(), configuration.getModelMap());

	play(game, windowManager, *renderer, eventHandler, configuration.getControlMap());

	delete renderer;

	return EXIT_SUCCESS;

}

// Main for linux
int main(int argc, char **argv) {
	return realMain();
}

// Main for windows
int WinMain(int argc, char **argv) {
	return realMain();
}
