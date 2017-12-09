#include <Renderer3D.h>

#include <GL/glew.h>
#include <Renderer.h>
#include <GameRepresentation.h>
#include <AbstractModel3D.h>
#include <NormalModel3D.h>
#include <glimac/Program.hpp>
#include <glimac/SDLWindowManager.hpp>

using namespace glimac;
using namespace glm;

const float Renderer3D::SQUARE_SIZE = 1;

AbstractModel3D * Renderer3D::get3DModel(GameRepresentation::Model model) {
	switch (model) {
		case GameRepresentation::Model::PACMAN:
			return new NormalModel3D;
		case GameRepresentation::Model::WALL:
			return new NormalModel3D;
		case GameRepresentation::Model::PAC_GOMME:
			return new NormalModel3D;
	}
}

Renderer3D::Renderer3D(SDLWindowManager * windowManager) : _windowManager(windowManager), _models() {
	for (auto & model : GameRepresentation::MODELS) {
		AbstractModel3D * model3d = get3DModel(model); // TODO free
		_models[model] = model3d;
	}
}
	
void Renderer3D::render(const GameRepresentation & repr) const {
	mat4 ProjMatrix, MVMatrix, NormalMatrix;
	ProjMatrix = perspective(radians(70.f), float(800)/600, 0.1f, 100.f); //TODO screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto & model : GameRepresentation::MODELS) {  
		vector<BoardPosition> positions = repr[model];
		AbstractModel3D * model3d = _models.at(model);
		model3d->bind();
		for (auto & position : positions) {
			// TODO better
			MVMatrix = translate(mat4(1.f), vec3(0, 0, -20));
			// TODO (x,y) on (x,0,y)
			MVMatrix = translate(MVMatrix, vec3(position.getX()*SQUARE_SIZE, position.getY()*SQUARE_SIZE, 0));
			NormalMatrix = transpose(inverse(MVMatrix));
			model3d->setMVPMatrix(ProjMatrix * MVMatrix);
			model3d->setMVMatrix(MVMatrix);
			model3d->setNormalMatrix(NormalMatrix);
			glDrawArrays(GL_TRIANGLES, 0, model3d->count());
		}
		model3d->unbind();
	}
	_windowManager->swapBuffers();
}
