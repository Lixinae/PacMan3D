#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <json/json.hpp>
#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <Game.h>
#include <Renderer.h>
#include <Renderer3D.h>
#include <EventHandler.h>


using namespace glimac;
using namespace std;
using namespace glm;

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

    bool done = false;
    while (!done) {

        if (eventHandler.handleEvent(windowManager, game)) {
            done = true;
        }

        renderer->render(game.getRepresentation(), game.getInformations());

		if(!game.iterate()) {
			//done = true;
		}

        windowManager.swapBuffers();
        
        //TODO sleep framerate
	    // TODO -> Virer ce truc , framerate et vitesse devraient être indépendant !
        this_thread::sleep_for(chrono::milliseconds(66));

    }

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
