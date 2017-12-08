#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Image.hpp>
#include <cstddef>
#include <Game.h>
#include <Renderer.h>
#include <Renderer3D.h>
#include <json/json.hpp>
#include <EventHandler.hpp>
#include <Camera.h>
#include <FreeflyCamera.h>
#include <TrackballCamera.h>

using namespace glimac;
using namespace std;
using namespace glm;

using json = nlohmann::json;

int main(int argc, char **argv) {

    float l = 800, h = 600;
    SDLWindowManager windowManager(l, h, "GLImac");

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

    Renderer *renderer = new Renderer3D(&windowManager);

    bool done = false;
    EventHandler eventHandler;
    double speed = 1;
//    Todo -> avoir une classe mere de camera pour changer facilement entre les 2 implementations
    Camera camera;
    TrackballCamera trackballCamera;
    FreeflyCamera freeflyCamera;
    camera = trackballCamera;
    bool isTrackBall=true;
    while (!done) {
        SDL_Event event{};
        while (windowManager.pollEvent(event)) {
            eventHandler.handleEvent(event);


        }
        if (eventHandler.exitProgram()) {
            done = true;
        }

        if (eventHandler.changeCamera()) {
            if(isTrackBall){
                camera = freeflyCamera;
                isTrackBall = false;
            }else{
                camera = trackballCamera;
                isTrackBall = true;
            }
            eventHandler.set_changeCamera(false);
        }
// Todo -> La gestion des controle de la camera doit etre identique il faut donc une classe camera mere des 2
        if(eventHandler.moveUp()){
            camera.moveFront(1.*speed);
        }
        else if(eventHandler.moveDown()){
            camera.moveFront(-1.*speed);
        }
        if(eventHandler.moveLeft()){
            camera.moveHorizontal(1.*speed);
        }
        else if(eventHandler.moveRight()){
            camera.moveHorizontal(-1.*speed);
        }
        if(eventHandler.mouseRight()){
            camera.rotateHorizontal(event.motion.xrel);
            camera.rotateVertical(event.motion.yrel);
        }
        if (eventHandler.activateSpeed()) {
            if (eventHandler.speedUp()) {
                speed += 0.02;
            } else if (eventHandler.speedDown()) {
                speed -= (speed - 0.02 >= 0 ? 0.02 : 0.);
            }
        }

        renderer->render(game.getRepresentation());
    }

    delete renderer;

    return EXIT_SUCCESS;

} 
