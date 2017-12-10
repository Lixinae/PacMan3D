#include <Renderer3D.h>

#include <GL/glew.h>
#include <Renderer.h>
#include <GameRepresentation.h>
#include <AbstractModel3D.h>
#include <NormalModel3D.h>
#include <TexModel3D.h>
#include <glimac/Program.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <PointOfView.h>
#include <Camera.h>

using namespace glimac;
using namespace glm;

const float Renderer3D::SQUARE_SIZE = 1;

AbstractModel3D * Renderer3D::get3DModel(GameRepresentation::Model model) {
	switch (model) {
		case GameRepresentation::Model::PACMAN:
			return new TexModel3D("assets/textures/EarthMap.jpg");
		case GameRepresentation::Model::WALL:
			return new TexModel3D("assets/textures/MoonMap.jpg");
		case GameRepresentation::Model::PAC_GOMME:
			return new TexModel3D("assets/textures/MoonMap.jpg");
	}
}

Renderer3D::Renderer3D(SDLWindowManager * windowManager, int windowWidth, int windowHeight, PointOfView * pointOfView) : _windowManager(windowManager), _pointOfView(pointOfView), ProjMatrix(perspective(radians(70.f), float(windowWidth)/windowHeight, 0.1f, 100.f)), _models() {
	for (auto & model : GameRepresentation::MODELS) {
		AbstractModel3D * model3d = get3DModel(model); // TODO free
		_models[model] = model3d;
	}
}
	
void Renderer3D::render(const GameRepresentation & repr) const {
	mat4 GlobalMVMatrix = _pointOfView->getCamera()->getViewMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto & model : GameRepresentation::MODELS) {  
		vector<BoardPosition> positions = repr[model];
		AbstractModel3D * model3d = _models.at(model);
		model3d->bind();
		for (auto & position : positions) {
			mat4 MVMatrix = translate(GlobalMVMatrix, vec3(position.getX()*SQUARE_SIZE, 0, -position.getY()*SQUARE_SIZE));
			model3d->setMatrices(ProjMatrix, MVMatrix);
			glDrawArrays(GL_TRIANGLES, 0, model3d->count());
		}
		model3d->unbind();
	}
	_windowManager->swapBuffers();
}
