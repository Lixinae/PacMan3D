#include <Renderer3D.h>

#include <GameRepresentation.h>
#include <GL/glew.h>
#include <glimac/glm.hpp>
#include <glimac/Program.hpp>
#include <glimac/SDLWindowManager.hpp>

using namespace glimac;
using namespace glm;

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
	program = loadProgram("shaders/3D.vs.glsl", "shaders/normal.fs.glsl");
	program.use();
	uMVPmatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    uMVmatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    uNormalmatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
}
	
void Renderer3D::render(const GameRepresentation & repr) const {
	mat4 ProjMatrix, MVMatrix, NormalMatrix;
	ProjMatrix = perspective(radians(70.f), float(800)/600, 0.1f, 100.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto & model : GameRepresentation::MODELS) {  
		vector<BoardPosition> positions = repr[model];
		Model3D model3d = _models.at(model);
		model3d.bindVAO();
		for (auto & position : positions) {
			// TODO better
			MVMatrix = translate(mat4(1.f), vec3(0, 0, -5));
			MVMatrix = translate(MVMatrix, vec3(position.getX()/4., position.getX()/4., 0));
			NormalMatrix = transpose(inverse(MVMatrix));
			glUniformMatrix4fv(uMVPmatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
			glUniformMatrix4fv(uMVmatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
			glUniformMatrix4fv(uNormalmatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
			glDrawArrays(GL_TRIANGLES, 0, model3d.count());
		}
		model3d.unbindVAO();
	}
	_windowManager->swapBuffers();
}
