#ifndef __RENDERER_3D_H__
#define __RENDERER_3D_H__

#include <GL/glew.h>
#include <Renderer.h>
#include <GameRepresentation.h>
#include <AbstractModel3D.h>
#include <glimac/Program.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <Camera.h>

using namespace glimac;

class Renderer3D : public Renderer {

public:

	static const float SQUARE_SIZE;

	Renderer3D(SDLWindowManager * windowManager, int windowWidth, int windowHeight, Camera * camera); //TODO private + take in argument the map of BoardRepresentation->Model3D  

	void render(const GameRepresentation & repr) const;

private:

	SDLWindowManager * _windowManager;
	mat4 ProjMatrix;
	Camera * _camera;
	map<GameRepresentation::Model, AbstractModel3D *> _models;

	static AbstractModel3D * get3DModel(GameRepresentation::Model model);

};

#endif
