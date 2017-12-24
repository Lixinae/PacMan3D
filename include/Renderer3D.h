#ifndef __RENDERER_3D_H__
#define __RENDERER_3D_H__

#include <GL/glew.h>
#include <Renderer.h>
#include <GameRepresentation.h>
#include <AbstractModel3D.h>
#include <glimac/Program.hpp>
#include <PointOfView.h>
#include <ColorText2DRenderer.h>

using namespace glimac;

class Renderer3D : public Renderer {

public:

	static const float SQUARE_SIZE;

	Renderer3D(int windowWidth, int windowHeight, PointOfView * pointOfView,const map<GameRepresentation::ModelType, AbstractModel3D *> & map_model3D);

	void render(const GameRepresentation & repr) const;

    ~Renderer3D() override;

private:

	mat4 _ProjMatrix;
	PointOfView * _pointOfView;
	map<GameRepresentation::ModelType, AbstractModel3D *> _models;
	ColorText2DRenderer _textRenderer;
	
	void renderModels(const GameRepresentation & repr) const;
	void renderTexts() const;

};

#endif
