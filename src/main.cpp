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

void play(Game & game, SDLWindowManager & windowManager, Renderer & renderer, EventHandler & eventHandler) {

	// TODO renderer::renderBeginTitle//
	cout << "DEBUT DU JEU" << endl;
	cout << "APPUYEZ SUR UNE TOUCHE" << endl;
	//
	
	//eventHandler::handleBeginTitleEvent//
	SDL_Event event;
	bool stop = false;
	while (!stop) {
		while (windowManager.pollEvent(event)) {
			if (event.type == SDL_QUIT) {
				return;
			}
			if (event.type == SDL_KEYDOWN) {
				stop = true;
			}
		}
	}
	
    while (!game.isFinish()) {

		renderer.render(game.getRepresentation(), game.getInformations());
		windowManager.swapBuffers();

		//
		cout << "APPUYEZ SUR ENTREE POUR COMMENCER" << endl;
		//
	
		//
		SDL_Event event;
		bool stop = false;
		while (!stop) {
			while (windowManager.pollEvent(event)) {
				if (event.type == SDL_QUIT) {
					return;
				}
				if (event.type == SDL_KEYDOWN) {
					if (event.key.keysym.sym == SDLK_RETURN){
						stop = true;
					}
				}
			}
		}
		//
		
		while (game.iterate()) {
			
			if (eventHandler.handleEvent(windowManager, game)) {
				return;
			}

			renderer.render(game.getRepresentation(), game.getInformations());

			windowManager.swapBuffers();
		
			this_thread::sleep_for(chrono::milliseconds(66));
		}
		game.reset();

    }
    
    
    //
	cout << "FIN DU JEU" << endl;
	cout << "APPUYEZ SUR UNE TOUCHE POUR FINIR" << endl;
	//
	
	//
	stop = false;
	while (!stop) {
		while (windowManager.pollEvent(event)) {
			if (event.type == SDL_QUIT) {
				return;
			}
			if (event.type == SDL_KEYDOWN) {
				stop = true;
			}
		}
	}
	//
	
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
