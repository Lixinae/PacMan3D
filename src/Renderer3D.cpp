#include <Renderer3D.h>

#include <GameRepresentation.h>
#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>

using namespace glimac;

Renderer3D::Renderer3D(SDLWindowManager * windowManager) : _windowManager(windowManager), _models() {
	for (auto & model : GameRepresentation::MODELS) {  
		_models[model] = Model3D();
	}
}
	
void Renderer3D::render(const GameRepresentation & repr) const {
	glClear(GL_COLOR_BUFFER_BIT);
	for (auto & model : GameRepresentation::MODELS) {  
		vector<BoardPosition> positions = repr[model];
		for (auto & position : positions) {
			Model3D model3d = _models.at(model);
			model3d.bindVAO();
			glDrawArrays(GL_TRIANGLES, 0, model3d.count());
			model3d.unbindVAO();
		}
	}
	_windowManager->swapBuffers();
}
