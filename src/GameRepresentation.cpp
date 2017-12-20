#include <GameRepresentation.h>

using namespace std;

// Laisser cette ligne sinon erreur !
vector<GameRepresentation::ModelType> GameRepresentation::MODELS;

vector<GameRepresentation::ModelType> GameRepresentation::buildVector() {
	vector<GameRepresentation::ModelType> models;
	models.push_back(GameRepresentation::ModelType::PACMAN);
	models.push_back(GameRepresentation::ModelType::WALL);
	models.push_back(GameRepresentation::ModelType::FLOOR);
	models.push_back(GameRepresentation::ModelType::TUNNEL);
	models.push_back(GameRepresentation::ModelType::PAC_GOMME);
	return models;
}

GameRepresentation::ModelType GameRepresentation::modelFromString(const string & strModel) {
    if (strModel == "Pacman") {
		 return GameRepresentation::ModelType::PACMAN;
    }
    if (strModel == "Wall") {
		return GameRepresentation::ModelType::WALL;
    }
    if (strModel == "Floor") {
		return GameRepresentation::ModelType::FLOOR;
	}
    if (strModel == "Tunnel") {
		return GameRepresentation::ModelType::TUNNEL;
    }
    if (strModel == "Pac_gomme") {
		return GameRepresentation::ModelType::PAC_GOMME;
	}
}

GameRepresentation::ModelInformations::ModelInformations(const BoardPosition & position, Utils::Orientation orientation) :
	position(position),
	orientation(orientation)
{
	
}

GameRepresentation::GameRepresentation() :
		_modelsPositions() {
	GameRepresentation::MODELS = buildVector(); //TODO enlever
	for (auto & modelType : GameRepresentation::MODELS) {
		_modelsPositions[modelType] = vector<ModelInformations>();
	}
}
	
const vector<GameRepresentation::ModelInformations> & GameRepresentation::getPositions(ModelType modelType) const {
	return _modelsPositions.at(modelType);
}

void GameRepresentation::add(ModelType modelType, const BoardPosition & position) {
	// TODO implement
	GameRepresentation::ModelInformations information(position, Utils::Orientation::NORTH);
	_modelsPositions[modelType].push_back(information);
}
	
void GameRepresentation::remove(ModelType modelType, const BoardPosition & position) {
	vector<GameRepresentation::ModelInformations> & informations = _modelsPositions[modelType];	
	informations.erase(std::remove_if(informations.begin(), informations.end(), [position](const GameRepresentation::ModelInformations & information) {
		return (information.position == position); // TODO && info.orient ==
	}), informations.end());
}
	
const vector<GameRepresentation::ModelInformations> & GameRepresentation::operator[](ModelType modelType) const {
	return getPositions(modelType);
}
