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
#include <NormalModel3D.h>

using namespace glimac;
using namespace std;
using namespace glm;

using json = nlohmann::json;

// Todo mettre ailleurs -> Besoin pour creer la map avant de le faire dans le rendere
// Pour correspondre au nouveau constructeur
AbstractModel3D *get3DModel(GameRepresentation::Model model) {
    mat4 modelTransform(1);
    switch (model) {
        case GameRepresentation::Model::PACMAN:
            modelTransform = scale(modelTransform, vec3(0.006, 0.006, 0.006));
            return new TexModel3D("assets/models/tennisball.obj", "assets/textures/EarthMap.jpg", modelTransform);
        case GameRepresentation::Model::WALL:
//            modelTransform = scale(modelTransform, vec3(0.4, 0.4, 0.4));
            //return new TexModel3D("assets/models/cube.obj", "assets/textures/MoonMap.jpg", modelTransform);
            modelTransform = scale(modelTransform, vec3(0.4, 0.2, 0.08));
            return new TexModel3D("assets/models/wall.obj", "assets/textures/wall.jpg", modelTransform);
        case GameRepresentation::Model::FLOOR:
            modelTransform = scale(modelTransform, vec3(0.5, 0.1, 0.5));
            return new TexModel3D("assets/models/cube.obj", "assets/textures/EarthMap.jpg", modelTransform);
        case GameRepresentation::Model::TUNNEL:
            modelTransform = scale(modelTransform, vec3(0.4, 0.4, 0.4));
            return new TexModel3D("assets/models/cube.obj", "assets/textures/EarthMap.jpg", modelTransform);
        case GameRepresentation::Model::PAC_GOMME:
            modelTransform = scale(modelTransform, vec3(0.0025, 0.0025, 0.0025));
            //return new TexModel3D("assets/models/cube.obj", "assets/textures/MoonMap.jpg", modelTransform);
            return new NormalModel3D("assets/models/tennisball.obj", modelTransform);
    }
}


int realMain() {

    Configuration configuration = Configuration::fromJSONFile("assets/configurations/configuration.json");

    int windowWidth = configuration.getWidth();
    int windowHeight = configuration.getHeight();
    SDLWindowManager windowManager(windowWidth, windowHeight, "GLImac");
    
    GLenum glewInitError = glewInit();
    if (GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    glEnable(GL_DEPTH_TEST);

    Game game = Game::fromJSONFile("assets/games/game.json");

	EventHandler eventHandler(configuration.getControlMap());

    map<GameRepresentation::Model, AbstractModel3D *> map_model3D;

    // todo -> virer plus tard
    for (auto &model : GameRepresentation::MODELS) {
        AbstractModel3D *model3d = get3DModel(model);
        map_model3D.insert(pair<GameRepresentation::Model, AbstractModel3D *>(model, model3d));
    }
    Renderer *renderer = new Renderer3D(windowWidth, windowHeight, game.getPointOfView(), map_model3D);
//    Renderer *renderer = new Renderer3D(windowWidth, windowHeight, game.getPointOfView());

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
