#include <Renderer3D.h>
#include <NormalModel3D.h>
#include <TexModel3D.h>

using namespace glimac;
using namespace glm;

const float Renderer3D::SQUARE_SIZE = 1;

Renderer3D::Renderer3D(int windowWidth, int windowHeight, PointOfView *pointOfView, const map<GameRepresentation::ModelType, AbstractModel3D *>& map_model3D) :
        _pointOfView(pointOfView),
        _ProjMatrix(perspective(radians(70.f), float(windowWidth) / windowHeight, 0.1f, 100.f)),
        _models(map_model3D) 
{

}

void Renderer3D::render(const GameRepresentation &repr) const {
    mat4 GlobalMVMatrix = _pointOfView->getCurrentCamera().getViewMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (auto & modelType : GameRepresentation::MODELS) {
        vector<GameRepresentation::ModelInformations> informations = repr[modelType];
        AbstractModel3D * model3d = _models.at(modelType);
        model3d->bind();
        for (auto & information : informations) {
			BoardPosition position = information.position;
			Utils::Orientation orientation = information.orientation;
            mat4 MVMatrix = 
				rotate(
                    translate(
						GlobalMVMatrix,
						vec3(position.getX() * SQUARE_SIZE, 0, -position.getY() * SQUARE_SIZE)
					),
					radians(Utils::degreesOfOrientation(orientation)),
					vec3(0,1,0)
				);
            model3d->setMatrices(_ProjMatrix, MVMatrix);
            glDrawArrays(GL_TRIANGLES, 0, model3d->count());
        }
        model3d->unbind();
    }
}

Renderer3D::~Renderer3D() {
    for (auto &model : GameRepresentation::MODELS) {
        // TODO delete model (not free): 
        //free (_models[model]);
    }
}
