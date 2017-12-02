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
    
    Game game;
    
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
