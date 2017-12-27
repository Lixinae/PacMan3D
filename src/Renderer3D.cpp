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
			glDrawArrays(GL_TRIANGLES, 0, model3d->count());
		}
		model3d->unbind();
	}
}

void Renderer3D::renderTexts(const GameInformations &gameInfo) const {
	// Toutes les valeurs sont ajustés pour une grille orthogonal de 800*600
	int x = 10, y, ecart = 28;
	float scale = 0.5;
	vec3 color = vec3(1, 0.89, 0.8);

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

void Renderer3D::renderGame(const GameRepresentation &repr, const GameInformations &gameInfo) const {
	renderModels(repr);
	renderTexts(gameInfo);
}

void Renderer3D::renderBeginTitle() const {
	vec3 color = vec3(1, 0.89, 0.8);
	_textRenderer.render("PACMAN 3D", 100, 450, 0.75, color);
	_textRenderer.render("APPUYER SUR UNE TOUCHE", 100, 400, 0.65, color);
}

void Renderer3D::renderBeginGame() const {
	vec3 color = vec3(1, 0.89, 0.8);
	_textRenderer.render("APPUYER SUR ENTREE POUR COMMENCER", 100, 400, 0.65, color);
}

void Renderer3D::renderPauseMenu() const {
	vec3 color = vec3(1, 0.89, 0.8);
	_textRenderer.render("PAUSE", 300, 400, 0.8, color);
	_textRenderer.render("P : REPRENDRE", 100, 350, 0.7, color);
	_textRenderer.render("Q : QUITTER", 100, 300, 0.7, color);
	_textRenderer.render("S : SAUVEGARDER LA PARTIE", 100, 250, 0.7, color);
	_textRenderer.render("C : CHARGER LA DERNIERE PARTIE", 100, 200, 0.7, color);
}

void Renderer3D::renderEndTitle() const {
	vec3 color = vec3(1, 0.89, 0.8);
	_textRenderer.render("FIN DE LA PARTIE", 70, 450, 0.65, color);
	_textRenderer.render("APPUYER SUR UNE TOUCHE POUR QUITTER", 100, 400, 0.6, color);
}

Renderer3D::~Renderer3D() {
	for (auto &model : GameRepresentation::MODELS) {
		// TODO delete model (not free):
		//free (_models[model]);
	}
}
