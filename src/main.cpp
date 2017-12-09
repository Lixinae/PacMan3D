#include <iostream>
#include <cstddef>
#include <chrono>
#include <thread>
#include <fstream>
#include <json/json.hpp>
#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Image.hpp>
#include <Game.h>
#include <Renderer.h>
#include <Renderer3D.h>
#include <EventHandler.h>
#include <Camera.h>
#include <FreeflyCamera.h>
#include <TrackballCamera.h>

using namespace glimac;
using namespace std;
using namespace glm;

using json = nlohmann::json;

int main(int argc, char **argv) {

    int windowWidth = 800, windowHeight = 600;
    SDLWindowManager windowManager(windowWidth, windowHeight, "GLImac");

    GLenum glewInitError = glewInit();
    if (GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    glEnable(GL_DEPTH_TEST);


    json jsonGame;
    ifstream gameFile("assets/game/game.json");
    gameFile >> jsonGame;
    gameFile.close();
    Game game = Game::fromJSON(jsonGame);

	Camera * camera = new TrackballCamera;
	camera->moveFront(20);
	camera->rotateVertical(45);
	camera->rotateHorizontal(15);

    Renderer * renderer = new Renderer3D(&windowManager, windowWidth, windowHeight, camera);

    EventHandler eventHandler;
    
    //double speed = 1;
    //TrackballCamera trackballCamera;
    //FreeflyCamera freeflyCamera;
    //bool isTrackBall = true;

	bool done = false;
    while (!done) {
		
		Pacman & pacman = game.getPacman();
    
        SDL_Event event;
        while (windowManager.pollEvent(event)) {
            eventHandler.handleEvent(event);
        }
		
        if (eventHandler.exitProgram()) {
            done = true;
        }

		// TODO //
		if (windowManager.isKeyPressed(SDLK_z)) {
			cout << "z" << endl;
			pacman.setOrientation(Pacman::Orientation::NORTH);
		} else if (windowManager.isKeyPressed(SDLK_s)) {
			cout << "s" << endl;
			pacman.setOrientation(Pacman::Orientation::SOUTH);
		} else if (windowManager.isKeyPressed(SDLK_q)) {
			cout << "q" << endl;
			pacman.setOrientation(Pacman::Orientation::WEST);
		} else if (windowManager.isKeyPressed(SDLK_d)) {
			cout << "d" << endl;
			pacman.setOrientation(Pacman::Orientation::EAST);
		}
		// 		//


		/*
        if (eventHandler.changeCamera()) {
            isTrackBall = !isTrackBall;
            eventHandler.set_changeCamera(false);
        }

        if (isTrackBall) {
//            if(keyUp){
//                trackballCamera.rotateVertical(0.005);
//            }
//            else if(keyDown){
//                trackballCamera.rotateVertical(-0.005);
//            }
//            if(keyLeft){
//                trackballCamera.rotateHorizontal(-0.005);
//            }
//            else if(keyRight){
//                trackballCamera.rotateHorizontal(0.005);
//            }
//            if(eventHandler.mouseLeft()){
//                trackballCamera.moveFront(0.005);
//            }
//            else if(eventHandler.mouseRight()){
//                trackballCamera.moveFront(-0.005);
//            }
        } else {
            if (eventHandler.moveUp()) {
                freeflyCamera.moveFront(1. * speed);
            } else if (eventHandler.moveDown()) {
                freeflyCamera.moveFront(-1. * speed);
            }
            if (eventHandler.moveLeft()) {
                freeflyCamera.moveHorizontal(1. * speed);
            } else if (eventHandler.moveRight()) {
                freeflyCamera.moveHorizontal(-1. * speed);
            }
            if (eventHandler.mouseRight()) {
                freeflyCamera.rotateHorizontal(event.motion.xrel);
                freeflyCamera.rotateVertical(event.motion.yrel);
            }
        }
        if (eventHandler.activateSpeed()) {
            if (eventHandler.speedUp()) {
                speed += 0.02;
            } else if (eventHandler.speedDown()) {
                speed -= (speed - 0.02 >= 0 ? 0.02 : 0.);
            }
        }
        */

        renderer->render(game.getRepresentation());
        
        pacman.iterate();
        
        //TODO sleep framerate
        this_thread::sleep_for(chrono::milliseconds(50));
        
        
    }

	delete camera;
    delete renderer;

    return EXIT_SUCCESS;

} 
