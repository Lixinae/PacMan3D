#ifndef __RENDERER_3D_H__
#define __RENDERER_3D_H__

#include <Renderer.h>
#include <GameRepresentation.h>
#include <Model3D.h>
#include <glimac/Program.hpp>
#include <glimac/SDLWindowManager.hpp>

using namespace glimac;

class Renderer3D : public Renderer {

public:

	static const float SQUARE_SIZE;

	Renderer3D(SDLWindowManager * windowManager); //TODO private + take in argument the map of BoardRepresentation->Model3D  

	void render(const GameRepresentation & repr) const;

private:

	SDLWindowManager * _windowManager;
	map<GameRepresentation::Model, Model3D> _models;
	
	/* TODO maybe rm */
	GLuint uMVPmatrix; 
    GLuint uMVmatrix;
    GLuint uNormalmatrix;

	Program program; // TODO should be in model
	/*				 */

	Model3D get3DModel(GameRepresentation::Model model);

};

#endif
