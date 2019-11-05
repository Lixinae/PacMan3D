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

void waitFrameRate(int loop_time) {
	this_thread::sleep_for(chrono::milliseconds(50 - loop_time));
}

void waitFrameRate() {
	waitFrameRate(20);
}

void play(Game &game, SDLWindowManager &windowManager, Renderer &renderer, EventHandler &eventHandler, const map<control, SDLKey> &keyMap) {
	EventHandler::State state;
	state = EventHandler::State::CONTINUE;
	// Rendu du menu de base
	while (state == EventHandler::State::CONTINUE) {
		state = eventHandler.handleBeginTitleEvent(windowManager);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderer.renderBeginTitle();
		windowManager.swapBuffers();
	}
	// Indique si l'on a cliqué sur quitter
	if (state == EventHandler::State::QUIT) {
		return;
	}
	// Boucle principal
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
			state = eventHandler.handleGameEvent(windowManager, game);
			if (state == EventHandler::State::QUIT) {
				return;
			}
			// Si l'on appuie sur le bouton de pause
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
			const clock_t begin_time = clock();
			renderer.renderGame(game.getRepresentation(), game.getInformations());
			const clock_t end_time = clock();
			windowManager.swapBuffers();
			waitFrameRate(1000 * (float(end_time - begin_time)) / CLOCKS_PER_SEC);
		}
		// Si l'on gagne -> On va au niveau suivant
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

	Configuration configuration = Configuration::fromJSONFile("../assets/configurations/configuration.json");

	uint32_t windowWidth = configuration.getWidth();
	uint32_t windowHeight = configuration.getHeight();

	SDLWindowManager windowManager(windowWidth, windowHeight, "Pacman3D");

	GLenum glewInitError = glewInit();
	if (GLEW_OK != glewInitError) {
		cerr << glewGetErrorString(glewInitError) << endl;
		return EXIT_FAILURE;
	}

	srand(time(nullptr));

	glEnable(GL_DEPTH_TEST);

	Game game = Game::fromJSONFile("../assets/games/gameRealBoard.json");

	EventHandler eventHandler(configuration.getControlMap());

	BoardPosition lowerBound = game.getLowerBound();
	BoardPosition upperBound = game.getUpperBound();

	Renderer *renderer = new Renderer3D(windowWidth, windowHeight, game.getPointOfView(), configuration.getModelMap(), lowerBound, upperBound);

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
