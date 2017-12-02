#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Image.hpp>
#include <glimac/TrackballCamera.hpp>
#include <glimac/FreeflyCamera.hpp>
#include <cstddef>

#include <Game.h>
#include <Renderer.h>
#include <Renderer3D.h>

#include <json/json.hpp>
using json = nlohmann::json;

using namespace glimac;
using namespace std;
using namespace glm;

int main() {
		
    float l=800,h=600;
    SDLWindowManager windowManager(l,h, "GLImac");

    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }
    
    json jsonGame, jsonCases; 
    jsonCases = json::array({
		{{"position",{{"x",9}, {"y",10}}},{"case", {{"type","floor"}, {"args",json({})}}}},
		{{"position",{{"x",10}, {"y",10}}},{"case", {{"type","floor"}, {"args",json({})}}}},
		{{"position",{{"x",11}, {"y",10}}},{"case", {{"type","floor"}, {"args",json({})}}}}
	});
    jsonGame["pacman"]["position"]["x"] = 10;
    jsonGame["pacman"]["position"]["y"] = 10;
    jsonGame["pacman"]["orientation"] = "west";
    jsonGame["board"]["cases"] = jsonCases;
	
	cout << setw(4) << jsonGame << endl;
	
    Game game = Game::fromJSON(jsonGame);
    
    Renderer * renderer = new Renderer3D;
    
    bool done = false;
    while(!done) {
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true;
            }
        }
        renderer->render(game.getRepresentation());
    }
    
    delete renderer;
    
    return EXIT_SUCCESS;

} 
