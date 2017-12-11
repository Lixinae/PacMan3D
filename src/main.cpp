#include <iostream>
#include <cstddef>
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
#include <TrackballCamera.h>

using namespace glimac;
using namespace std;
using namespace glm;

using json = nlohmann::json;

int main(int argc, char **argv) {

    Configuration configuration = Configuration::fromJSONFile("assets/configuration.json");
    
    int windowWidth = configuration.getWidth();
    int windowHeight = configuration.getHeight();
    SDLWindowManager windowManager(windowWidth, windowHeight, "GLImac");

    GLenum glewInitError = glewInit();
    if (GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    glEnable(GL_DEPTH_TEST);

    Game game = Game::fromJSONFile("assets/game/game.json");

    Camera *camera1 = new TrackballCamera;
    camera1->moveFront(20);
    camera1->rotateVertical(45);
    camera1->rotateHorizontal(15);

    Camera *camera2 = new TrackballCamera;
    camera2->moveFront(20);
    camera2->rotateVertical(45);
    camera2->rotateHorizontal(-15);

    int icam = 1; //TODO change
    game.getPointOfView().setCamera(camera1);

	EventHandler eventHandler = EventHandler::fromConfiguration(configuration);
    Renderer *renderer = new Renderer3D(windowWidth, windowHeight, &(game.getPointOfView())); //TODO check adr function return

    //double speed = 1;
    //TrackballCamera trackballCamera;
    //FreeflyCamera freeflyCamera;
    //bool isTrackBall = true;

    bool done = false;
    while (!done) {

        Pacman &pacman = game.getPacman();

        SDL_Event event;
        while (windowManager.pollEvent(event)) {
            if (event.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }

            // todo -> recup le point of view ici et les 2 camera
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_c) {
                    cout << "c" << endl;
                    if (icam == 1) {
                        game.getPointOfView().setCamera(camera2);
                        icam = 2;
                    } else if (icam == 2) {
                        game.getPointOfView().setCamera(camera1);
                        icam = 1;
                    }
                }
            }
        }
		if (windowManager.isKeyPressed(SDLK_b)) {
			cout << "b" << endl;
			if (icam == 1) {
				camera1->moveFront(1);
			} else if (icam == 2) {
				camera2->moveFront(1);
			}
		}
		if (windowManager.isKeyPressed(SDLK_n)) {
			cout << "n" << endl;
			if (icam == 1) {
				camera1->moveFront(-1);
			} else if (icam == 2) {
				camera2->moveFront(-1);
			}
		}
	
		eventHandler.handleEvent(windowManager, game);
		
        renderer->render(game.getRepresentation());

        pacman.iterate();

		windowManager.swapBuffers();
		
        //TODO sleep framerate
        this_thread::sleep_for(chrono::milliseconds(50));

    }

    delete camera1;
    delete camera2;
    delete renderer;

    return EXIT_SUCCESS;

} 
