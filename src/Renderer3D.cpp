#include <Renderer3D.h>

using namespace std;
using namespace glimac;
using namespace glm;

Renderer3D::Renderer3D(
		int windowWidth, 
		int windowHeight, 
		const PointOfView &pointOfView,
		const map<GameRepresentation::ModelType, AbstractModel3D *> &map_model3D
	) :
        _pointOfView(pointOfView),
        _ProjMatrix(perspective(radians(70.f), float(windowWidth) / windowHeight, 0.1f, 100.f)),
        _models(map_model3D),
        _textRenderer(windowWidth, windowHeight, "assets/fonts/arial.ttf") //TODO static or from config
{

}

void Renderer3D::renderModels(const GameRepresentation &repr) const {
    mat4 GlobalMVMatrix = _pointOfView.getCurrentCamera().getViewMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (auto &modelType : GameRepresentation::MODELS) {
        vector<GameRepresentation::ModelInformations> informations = repr[modelType];
        AbstractModel3D *model3d = _models.at(modelType);
        model3d->bind();
        for (auto &information : informations) {
            BoardPosition position = information.position;
            Utils::Orientation orientation = information.orientation;
            mat4 MVMatrix =
                    rotate(
                            translate(
                                    GlobalMVMatrix,
                                    position.inSpace()
                            ),
                            radians(Utils::degreesOfOrientation(orientation)),
                            vec3(0, 1, 0)
                    );
            model3d->setMatrices(_ProjMatrix, MVMatrix);
            // todo -> ajout le materiau de l'objet pour les parametres
            model3d->setLightComponents(10.f);
            glDrawArrays(GL_TRIANGLES, 0, model3d->count());
        }
        model3d->unbind();
    }
}

void Renderer3D::renderTexts(const GameInformations &gameInfo) const {
    // Toutes les valeurs sont ajustés pour une grille orthogonal de 800*600
    int x = 10, y,ecart = 28;
    float scale = 0.5;
    const float divid = 255.f;
    vec3 color = vec3(255.f / divid, 229.f / divid,
                      204.f / divid); // -> Peut faire val.f/255.f pour avoir la valeur sur 1

    int livesLeft = gameInfo.getLives();
    y = 560;
    _textRenderer.render("Lives : " + to_string(livesLeft), x, y, scale, color);


    int currentScore = gameInfo.getScore();
    y -= ecart;
    _textRenderer.render("Score : " + to_string(currentScore), x, y, scale, color);


    int multiplier = gameInfo.getMultiplier();
    y -= ecart;
    _textRenderer.render("Multiplier : " + to_string(multiplier), x, y, scale, color);
}

void Renderer3D::render(const GameRepresentation &repr, const GameInformations &gameInfo) const {
    renderModels(repr);
    renderTexts(gameInfo);
}

Renderer3D::~Renderer3D() {
    for (auto &model : GameRepresentation::MODELS) {
        // TODO delete model (not free): 
        //free (_models[model]);
    }
}
