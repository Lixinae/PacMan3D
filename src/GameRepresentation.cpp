#include <GameRepresentation.h>

using namespace std;

// Laisser cette ligne sinon erreur !
vector<GameRepresentation::Model> GameRepresentation::MODELS;

vector<GameRepresentation::Model> GameRepresentation::buildVector() {
	vector<GameRepresentation::Model> models;
	models.push_back(GameRepresentation::Model::PACMAN);
	models.push_back(GameRepresentation::Model::WALL);
	models.push_back(GameRepresentation::Model::FLOOR);
	models.push_back(GameRepresentation::Model::TUNNEL);
	models.push_back(GameRepresentation::Model::PAC_GOMME);
	return models;
}

GameRepresentation::Model GameRepresentation::modelFromString(const string & strModel) {
    if (strModel == "Pacman") {
		 return GameRepresentation::Model::PACMAN;
    }
    if (strModel == "Wall") {
		return GameRepresentation::Model::WALL;
    }
    if (strModel == "Floor") {
		return GameRepresentation::Model::FLOOR;
	}
    if (strModel == "Tunnel") {
		return GameRepresentation::Model::TUNNEL;
    }
    if (strModel == "Pac_gomme") {
		return GameRepresentation::Model::PAC_GOMME;
	}
}

GameRepresentation::GameRepresentation() :
		_modelsPositions() {
	GameRepresentation::MODELS = buildVector(); //TODO enlever
	for (auto & model : GameRepresentation::MODELS) {
		_modelsPositions[model] = vector<BoardPosition>();
	}
}
	
const vector<BoardPosition> & GameRepresentation::getPositions(Model model) const {
	return _modelsPositions.at(model);
}

void GameRepresentation::add(Model model, const BoardPosition & position) {
	_modelsPositions[model].push_back(position);
}
	
void GameRepresentation::remove(Model model, const BoardPosition & position) {
	vector<BoardPosition> & positions = _modelsPositions[model];	
	positions.erase(std::remove(positions.begin(), positions.end(), position), positions.end());
}
	
const vector<BoardPosition> & GameRepresentation::operator[](Model model) const {
	return getPositions(model);
}
