#include <Renderer3D.h>

#include <GameRepresentation.h>
#include <GL/glew.h>
#include <glimac/glm.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/Program.hpp>

using namespace glimac;

/* todo remove */

glm::mat3 translate(float tx, float ty) {
  return glm::mat3(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0), glm::vec3(tx, ty, 1));
}

glm::mat3 scale(float sx, float sy) {
  return glm::mat3(glm::vec3(sx, 0, 0), glm::vec3(0, sy, 0), glm::vec3(0, 0, 1));
}

glm::mat3 rotate(float a) {
  float alpha = glm::radians(a);
  return glm::mat3(glm::vec3(glm::cos(alpha), glm::sin(alpha), 0), glm::vec3(-glm::sin(alpha), glm::cos(alpha), 0), glm::vec3(0, 0, 1));
}

/* todo remove */

Model3D Renderer3D::get3DModel(GameRepresentation::Model model) {
	float r = 1, g = 0, b = 0;
	if (model == GameRepresentation::Model::PAC_GOMME) {
		r = 1;
		g = 1;
		b = 0;
	}
	return Model3D(r,g,b);
}

Renderer3D::Renderer3D(SDLWindowManager * windowManager) : _windowManager(windowManager), _models() {
	for (auto & model : GameRepresentation::MODELS) {
		Model3D model3d = get3DModel(model);
		_models[model] = model3d;
	}
	Program program = loadProgram("shaders/triangle.vs.glsl", "shaders/triangle.fs.glsl");
	program.use();
	matrix = glGetUniformLocation(program.getGLId(), "uModelMatrix");
}
	
void Renderer3D::render(const GameRepresentation & repr) const {
	glClear(GL_COLOR_BUFFER_BIT);
	for (auto & model : GameRepresentation::MODELS) {  
		vector<BoardPosition> positions = repr[model];
		Model3D model3d = _models.at(model);
		model3d.bindVAO();
		for (auto & position : positions) {
			glm::mat3 transformations = translate(position.getX()/20., position.getY()/20.) * scale(0.1,0.1);
			glUniformMatrix3fv(matrix, 1, GL_FALSE, glm::value_ptr(transformations));
			glDrawArrays(GL_TRIANGLES, 0, model3d.count());
		}
		model3d.unbindVAO();
	}
	_windowManager->swapBuffers();
}
