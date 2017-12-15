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

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure

using namespace glimac;
using namespace std;
using namespace glm;

using json = nlohmann::json;

int realMain() {
    cout << "test" << endl;
    // Ligne de test
    Assimp::Importer importer;

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

    Camera * camera1 = new TrackballCamera;
    camera1->moveFront(20);
    camera1->rotateVertical(45);
    camera1->rotateHorizontal(15);

    Camera * camera2 = new TrackballCamera;
    camera2->moveFront(20);
    camera2->rotateVertical(45);
    camera2->rotateHorizontal(-15);

    game.getPointOfView().setCamera(camera1); // TODO change

    EventHandler eventHandler(configuration.getControlMap(), camera1, camera2);
    Renderer *renderer = new Renderer3D(windowWidth, windowHeight, &(game.getPointOfView())); //TODO check adr function return

    bool done = false;
    while (!done) {

        if (eventHandler.handleEvent(windowManager, game)) {
            done = true;
        }

        renderer->render(game.getRepresentation());

        game.iterate();

        windowManager.swapBuffers();

        //TODO sleep framerate
        this_thread::sleep_for(chrono::milliseconds(50));

    }

    delete camera1;
    delete camera2;
    delete renderer;

    return EXIT_SUCCESS;

}

// Main pour linux
int main(int argc, char **argv) {
    return realMain();
}

// Main pour windows
int WinMain(int argc, char **argv) {
    return realMain();

} 
