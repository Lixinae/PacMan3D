#include <iostream>
#include <cstddef>
#include <ctime>
#include <chrono>
#include <thread>
#include <json/json.hpp>
#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/Image.hpp>
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

void play(Game & game, SDLWindowManager & windowManager, Renderer & renderer, EventHandler & eventHandler) {

	EventHandler::State state;
	
	// TODO renderer::renderBeginTitle//
	cout << "DEBUT DU JEU" << endl;
	cout << "APPUYEZ SUR UNE TOUCHE" << endl;
	//
	
	state = EventHandler::State::CONTINUE;
	while (state == EventHandler::State::CONTINUE) {
		state = eventHandler.handleBeginTitleEvent(windowManager);
	}
	if (state == EventHandler::State::QUIT) {
		return;
	}
	
    while (!game.isFinish()) {

		renderer.render(game.getRepresentation(), game.getInformations());
		windowManager.swapBuffers();

		//
		cout << "APPUYEZ SUR ENTREE POUR COMMENCER" << endl;
		//
		state = EventHandler::State::CONTINUE;
		while (state == EventHandler::State::CONTINUE) {
			state = eventHandler.handleBeginGameEvent(windowManager, game);
			renderer.render(game.getRepresentation(), game.getInformations());
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
				//TODO
				while (true) {}
			}

			renderer.render(game.getRepresentation(), game.getInformations());
			windowManager.swapBuffers();
			waitFrameRate();
		}
		game.reset();

    }
    
    
    //
	cout << "FIN DU JEU" << endl;
	cout << "APPUYEZ SUR UNE TOUCHE POUR FINIR" << endl;
	//
	state = EventHandler::State::CONTINUE;
	while (state == EventHandler::State::CONTINUE) {
		state = eventHandler.handleEndTitleEvent(windowManager);
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

    Game game = Game::fromJSONFile("assets/games/game.json");

	EventHandler eventHandler(configuration.getControlMap());

	Renderer *renderer = new Renderer3D(windowWidth, windowHeight, game.getPointOfView(), configuration.getModelMap());

	play(game, windowManager, *renderer, eventHandler);
    
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
