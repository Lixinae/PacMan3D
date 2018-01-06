#include <Renderer3D.h>

using namespace std;
using namespace glimac;
using namespace glm;

Renderer3D::Renderer3D(
		int windowWidth,
		int windowHeight,
		const PointOfView &pointOfView,
		const map<GameRepresentation::ModelType, function<AbstractModel3D *()>> &map_model3D,
		BoardPosition lowerBound,
		BoardPosition upperBound
) :
		_pointOfView(pointOfView),
		_ProjMatrix(perspective(radians(70.f), float(windowWidth) / windowHeight, 0.1f, 100.f)),
		_models(),
		_textRenderer(windowWidth, windowHeight, "assets/fonts/game_over.ttf"),//TODO static or from config
		_lowerBound(lowerBound),
		_upperBound(upperBound) {
	for (auto &entry : map_model3D) {
		_models[entry.first] = entry.second();
	}
	_skybox = initSkybox();
}

Renderer3D::~Renderer3D() {
	Utils::cleanMap(_models);
}

void Renderer3D::renderSkyBox() const {

	// Render
	mat4 GlobalMVMatrix = _pointOfView.getCurrentCamera().getViewMatrix();
	BoardPosition position(0, 0);
	_skybox->bind();

	mat4 MVMatrix = translate(
			GlobalMVMatrix, position.inSpace()
	);

	_skybox->setMatrices(_ProjMatrix, MVMatrix);
	glDrawArrays(GL_TRIANGLES, 0, _skybox->count());

	_skybox->unbind();
}

TexModel3D *Renderer3D::initSkybox() const {
	mat4 transformations(1.f);

	float x = abs(_lowerBound.getX()) + abs(_upperBound.getX());
	float y = abs(_lowerBound.getY()) + abs(_upperBound.getY());
	float z = x;

	transformations = scale(transformations, vec3(x, y, z));

	TexModel3D *skybox = TexModel3D::create("assets/models/cube.obj", "assets/textures/skybox.png", transformations);
	return skybox;
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
			float shift = information.shift;
			mat4 MVMatrix =
					rotate(
							translate(
									GlobalMVMatrix,
									position.inSpace() + shift * Utils::vectorOfOrientation(orientation)
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
	float x = 1.25f, y, ecart = 5.f;
	float scale = 0.65;
	vec3 color = vec3(1, 1, 0);
	int livesLeft = gameInfo.getLives();
	y = 95.f;
	_textRenderer.render("Lives : " + to_string(livesLeft), x, y, scale, color);
	int currentScore = gameInfo.getScore();
	y -= ecart;
	_textRenderer.render("Score : " + to_string(currentScore), x, y, scale, color);
	int level = gameInfo.getLevel();
	y -= ecart;
	_textRenderer.render("Level : " + to_string(level), x, y, scale, color);
}

void Renderer3D::renderGame(const GameRepresentation &repr, const GameInformations &gameInfo) const {
	renderSkyBox();
	renderModels(repr);
	renderTexts(gameInfo);
}

void Renderer3D::renderBeginTitle() const {
	vec3 color = vec3(1, 1, 0);
	_textRenderer.renderXCentered("PACMAN 3D", 76, 1.f, color);
	_textRenderer.renderXCentered("@", 66, 1.f, color);
	_textRenderer.renderXCentered("Appuyer sur une touche", 60, 1.f, color);
}

void Renderer3D::renderBeginGame() const {
	vec3 color = vec3(1, 1, 0);
	_textRenderer.renderXCentered("Appuyer sur entree pour commencer", 50, 0.7, color);
}

void Renderer3D::renderPauseMenu(const map<control, SDLKey> &keyMap) const {
	vec3 color = vec3(1, 1, 0);
	_textRenderer.renderXCentered("Pause", 70, 0.8, color);
	SDLKey key = keyMap.find(control::PAUSE_GAME)->second;
	_textRenderer.renderXCentered(Utils::stringToUpper(Utils::keyToString(key)) + " : Reprendre", 65, 0.7, color);
	key = keyMap.find(control::EXIT)->second;
	_textRenderer.renderXCentered(Utils::stringToUpper(Utils::keyToString(key)) + " : Quitter", 60, 0.7, color);
	key = keyMap.find(control::SAVE_GAME)->second;
	_textRenderer.renderXCentered(Utils::stringToUpper(Utils::keyToString(key)) + " : Sauvegarder la partie", 55, 0.7, color);
	key = keyMap.find(control::LOAD_GAME)->second;
	_textRenderer.renderXCentered(Utils::stringToUpper(Utils::keyToString(key)) + " : Charger la derniere partie", 50, 0.7, color);
	key = keyMap.find(control::RESTART)->second;
	_textRenderer.renderXCentered(Utils::stringToUpper(Utils::keyToString(key)) + " : Recommencer la partie", 45, 0.7, color);
}

void Renderer3D::renderEndTitle(const GameInformations &gameInfo) const {
	vec3 color = vec3(1, 1, 0);

	_textRenderer.renderXCentered("Fin de la partie", 75, 0.65, color);
	_textRenderer.renderXCentered("Score :" + to_string(gameInfo.getScore()), 70, 0.65, color);
	_textRenderer.renderXCentered("Level : " + to_string(gameInfo.getLevel()), 65, 0.65, color);
	_textRenderer.renderXCentered("Appuyer sur entree pour quitter", 60, 0.65, color);
}

