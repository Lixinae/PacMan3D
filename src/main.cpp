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

#include <Renderer.h>
#include <Renderer3D.h>
#include <BoardRepresentation.h>

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
    
    BoardRepresentation br;
    br.add(BoardRepresentation::Model::WALL, BoardPosition(15,15));
    br.add(BoardRepresentation::Model::WALL, BoardPosition(25,13));
    br.add(BoardRepresentation::Model::WALL, BoardPosition(30,33));
    br.add(BoardRepresentation::Model::WALL, BoardPosition(25,25));
    br.add(BoardRepresentation::Model::WALL, BoardPosition(28,28));
    
    Renderer * renderer = new Renderer3D;
    
    bool done = false;
    while(!done) {
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true;
            }
        }
        renderer->render(br);
    }
    
    delete renderer;
    
    return EXIT_SUCCESS;

} 
