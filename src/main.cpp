#include <iostream>
#include <ctime>
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
	this_thread::sleep_for(chrono::milliseconds(38));
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
	while (true) {
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
		Game::State gameState = Game::State::CONTINUE;
		while (gameState == Game::State::CONTINUE) {
			gameState = game.iterate();
			const clock_t atime = clock();
			state = eventHandler.handleGameEvent(windowManager, game);
			cerr << "a " << 1000 * (float( clock () - atime ) /  CLOCKS_PER_SEC) << endl;
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
			const clock_t btime = clock();
			renderer.renderGame(game.getRepresentation(), game.getInformations());
			cerr << "b " << 1000*(float( clock () - btime )) /  CLOCKS_PER_SEC << endl;
			const clock_t ctime = clock();
			windowManager.swapBuffers();
			cerr << "c " << 1000*(float( clock () - ctime ) /  CLOCKS_PER_SEC) << endl;
			waitFrameRate();
		}
		if (gameState == Game::State::WIN) {
			game.setNextLevel();
		} else if (gameState == Game::State::RESTART) {
			game.reset();
		} else {
			break;
		}
	}
	state = EventHandler::State::CONTINUE;
	while (state == EventHandler::State::CONTINUE) {
		state = eventHandler.handleEndTitleEvent(windowManager);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderer.renderEndTitle(game.getInformations());
		windowManager.swapBuffers();
	}

}

int realMain() {

	Configuration configuration = Configuration::fromJSONFile("assets/configurations/configuration.json");

	int windowWidth = configuration.getWidth();
	int windowHeight = configuration.getHeight();

	SDLWindowManager windowManager(windowWidth, windowHeight, "Pacman3D");

	GLenum glewInitError = glewInit();
	if (GLEW_OK != glewInitError) {
		cerr << glewGetErrorString(glewInitError) << endl;
		return EXIT_FAILURE;
	}

	srand(time(nullptr));

	glEnable(GL_DEPTH_TEST);

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
