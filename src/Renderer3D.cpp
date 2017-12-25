#include <Renderer3D.h>

using namespace std;
using namespace glimac;
using namespace glm;

Renderer3D::Renderer3D(int windowWidth, int windowHeight, const PointOfView & pointOfView, const map<GameRepresentation::ModelType, AbstractModel3D *>& map_model3D) :
        _pointOfView(pointOfView),
        _ProjMatrix(perspective(radians(70.f), float(windowWidth) / windowHeight, 0.1f, 100.f)),
        _models(map_model3D),
		_textRenderer(windowWidth, windowHeight, "assets/fonts/arial.ttf") //TODO static or from config
{

}

void Renderer3D::renderModels(const GameRepresentation &repr) const {
    mat4 GlobalMVMatrix = _pointOfView.getCurrentCamera().getViewMatrix();
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
						position.inSpace()
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

void Renderer3D::renderTexts() const {
	static int bidule = 0;
	bidule++;
	string text = "Mon texte avec I = " + to_string(bidule);
	_textRenderer.render(text, 100.f, 100.f, 1.f, vec3(0.3, 0.7f, 0.9f));

    int x,y,scale;
    vec3 color ; // -> Peut faire val.f/255.f pour avoir la valeur sur 1
    /*
    // TODO -> Render Lives left
    int livesLeft = ; // todo -> get the value
    text = "Lives : "+ to_string(livesLeft);
    x = ; // todo -> Set X & y & scale & color
    y = ;
    scale = ;
    color = ;
    _textRenderer.render(text, x, y, scale, color);

    // TODO -> Render Current Score
    int currentScore = ;
    text = "Score : "+ to_string(currentScore);
    x = ; // todo -> Set X & y & scale & color
    y = ;
    scale = ;
    color = ;
    _textRenderer.render(text, x, y, scale, color);
    // TODO -> Render multiplier

    int livesLeft = ;
    text = "Lives : "+ to_string(livesLeft);
    x = ; // todo -> Set X & y & scale & color
    y = ;
    scale = ;
    color = ;
    _textRenderer.render(text, x, y, scale, color);
    */


}

void Renderer3D::render(const GameRepresentation &repr) const {
	renderModels(repr);
	renderTexts();
}

Renderer3D::~Renderer3D() {
    for (auto &model : GameRepresentation::MODELS) {
        // TODO delete model (not free): 
        //free (_models[model]);
    }
}
