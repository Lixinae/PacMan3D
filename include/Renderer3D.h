#ifndef __RENDERER_3D_H__
#define __RENDERER_3D_H__

#include <GL/glew.h>
#include <Renderer.h>
#include <GameRepresentation.h>
#include <AbstractModel3D.h>
#include <glimac/Program.hpp>
#include <PointOfView.h>

using namespace glimac;

class Renderer3D : public Renderer {

public:

	static const float SQUARE_SIZE;

	Renderer3D(int windowWidth, int windowHeight, PointOfView * pointOfView); //TODO private + take in argument the map of BoardRepresentation->Model3D
	Renderer3D(int windowWidth, int windowHeight, PointOfView * pointOfView,const map<GameRepresentation::Model, AbstractModel3D *>& map_model3D);

	void render(const GameRepresentation & repr) const override;

    ~Renderer3D() override;

private:

	mat4 _ProjMatrix;
	PointOfView * _pointOfView;
	map<GameRepresentation::Model, AbstractModel3D *> _models;

	static AbstractModel3D * get3DModel(GameRepresentation::Model model);

};

#endif
