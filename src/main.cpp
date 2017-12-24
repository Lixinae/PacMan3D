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


#include <ColorText2D.h>


using namespace glimac;
using namespace std;
using namespace glm;

int realMain() {

    int windowWidth = 800;
    int windowHeight = 600;

    SDLWindowManager windowManager(windowWidth, windowHeight, "GLImac");

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

    ////// INIT 2D //////
    string fontLoc = "./assets/fonts/arial.ttf";
    ColorText2D colorText(windowWidth,windowHeight,fontLoc);
    ///// INIT 2D //////

    bool done = false;
    int bidule=0;
    while (!done) {

        if (eventHandler.handleEvent(windowManager, game)) {
            done = true;
        }

        renderer->render(game.getRepresentation());

        if(!game.iterate()) {
			    done = true;
    		}

        string text = "Mon texte avec I = " + to_string(bidule);
        colorText.render(text,100.f,100.f,1.f,glm::vec3(0.3, 0.7f, 0.9f));

        windowManager.swapBuffers();
        bidule++;
        //TODO sleep framerate
        this_thread::sleep_for(chrono::milliseconds(50));

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
