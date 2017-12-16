#include <Renderer3D.h>
#include <NormalModel3D.h>
#include <TexModel3D.h>

using namespace glimac;
using namespace glm;

const float Renderer3D::SQUARE_SIZE = 1;

AbstractModel3D * Renderer3D::get3DModel(GameRepresentation::Model model) {
	mat4 modelTransform(1);
	switch (model) {
		case GameRepresentation::Model::PACMAN:
			modelTransform = scale(modelTransform, vec3(0.6, 0.6, 0.6));
			//return new TexModel3D("assets/models/cube.obj", "assets/textures/EarthMap.jpg");
			return new NormalModel3D("assets/models/cube.obj", modelTransform);
		case GameRepresentation::Model::WALL:
			modelTransform = scale(modelTransform, vec3(0.4, 0.4, 0.4));
			return new TexModel3D("assets/models/cube.obj", "assets/textures/MoonMap.jpg", modelTransform);
		case GameRepresentation::Model::FLOOR:
			modelTransform = scale(modelTransform, vec3(0.4, 0.4, 0.4));
			return new TexModel3D("assets/models/cube.obj", "assets/textures/MoonMap.jpg", modelTransform);
		case GameRepresentation::Model::TUNNEL:
			modelTransform = scale(modelTransform, vec3(0.4, 0.4, 0.4));
			return new TexModel3D("assets/models/cube.obj", "assets/textures/EarthMap.jpg", modelTransform);
		case GameRepresentation::Model::PAC_GOMME:
			modelTransform = scale(modelTransform, vec3(0.4, 0.4, 0.4));
			return new TexModel3D("assets/models/cube.obj", "assets/textures/MoonMap.jpg", modelTransform);
	}
}

Renderer3D::Renderer3D(int windowWidth, int windowHeight, PointOfView *pointOfView) :
	_pointOfView(pointOfView),
	_ProjMatrix(perspective(radians(70.f), float(windowWidth) / windowHeight, 0.1f, 100.f)),
	_models() 
{
    for (auto &model : GameRepresentation::MODELS) {
        AbstractModel3D *model3d = get3DModel(model); // TODO free
        _models[model] = model3d;
    }
}

/* TODO -> Ajouter l'utilisation de shaders differents selon les objets à dessiner
 * On peut se servir de la structure "Program" que le prof avait donné dans le tp sur le multi-texturing
 * */
void Renderer3D::render(const GameRepresentation &repr) const {
    mat4 GlobalMVMatrix = _pointOfView->getCurrentCamera().getViewMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (auto &model : GameRepresentation::MODELS) {
        vector<BoardPosition> positions = repr[model];
        AbstractModel3D *model3d = _models.at(model);
        model3d->bind();
        for (auto &position : positions) {
            mat4 MVMatrix = translate(
				GlobalMVMatrix,
				vec3(position.getX() * SQUARE_SIZE, 0, -position.getY() * SQUARE_SIZE)
			);
            model3d->setMatrices(_ProjMatrix, MVMatrix);
            glDrawArrays(GL_TRIANGLES, 0, model3d->count());
        }
        model3d->unbind();
    }
}
