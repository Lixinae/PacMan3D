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
//#include <ft2build.h>
//#include FT_FREETYPE_H

using namespace glimac;
using namespace std;
using namespace glm;

using json = nlohmann::json;

int realMain() {

	/*
    FT_Library ft;
    if (FT_Init_FreeType(&ft))
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

    FT_Face face;
    if (FT_New_Face(ft, "assets/fonts/arial.ttf", 0, &face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
     */
    // Todo -> Tester l'écriture dans la boucle de rendu
    // Voir lien https://learnopengl.com/#!In-Practice/Text-Rendering


    int windowWidth = 800;
    int windowHeight = 600;
    
    SDLWindowManager windowManager(windowWidth, windowHeight, "GLImac");
    
    GLenum glewInitError = glewInit();
    if (GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

	srand(time(nullptr)); 

	glEnable(GL_DEPTH_TEST);
	
	Configuration configuration = Configuration::fromJSONFile("assets/configurations/configuration.json");

    Game game = Game::fromJSONFile("assets/games/game.json");

	EventHandler eventHandler(configuration.getControlMap());

	Renderer *renderer = new Renderer3D(windowWidth, windowHeight, game.getPointOfView(), configuration.getModelMap());

    bool done = false;
    while (!done) {

        if (eventHandler.handleEvent(windowManager, game)) {
            done = true;
        }

        renderer->render(game.getRepresentation());

        if(!game.iterate()) {
			done = true;
		}

        windowManager.swapBuffers();

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
