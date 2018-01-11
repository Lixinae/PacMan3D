#include <GameRepresentation.h>

using namespace std;

const vector<GameRepresentation::ModelType> GameRepresentation::MODELS() {
	vector<ModelType> models = {
			GameRepresentation::ModelType::PACMAN,
			GameRepresentation::ModelType::GHOST_BLINKY,
			GameRepresentation::ModelType::GHOST_PINKY,
			GameRepresentation::ModelType::GHOST_INKY,
			GameRepresentation::ModelType::GHOST_CLYDE,
			GameRepresentation::ModelType::GHOST_WEAK,
			GameRepresentation::ModelType::WALL,
			GameRepresentation::ModelType::FLOOR,
			GameRepresentation::ModelType::TUNNEL,
			GameRepresentation::ModelType::DOOR,
			GameRepresentation::ModelType::PAC_GOMME,
			GameRepresentation::ModelType::SUPER_PAC_GOMME,
			GameRepresentation::ModelType::FRUIT
	};
	return models;
}

GameRepresentation::ModelType GameRepresentation::modelFromString(const string &strModel) {
	if (strModel == "Pacman") {
		return GameRepresentation::ModelType::PACMAN;
	}
	if (strModel == "Ghost_blinky") {
		return GameRepresentation::ModelType::GHOST_BLINKY;
	}
	if (strModel == "Ghost_pinky") {
		return GameRepresentation::ModelType::GHOST_PINKY;
	}
	if (strModel == "Ghost_inky") {
		return GameRepresentation::ModelType::GHOST_INKY;
	}
	if (strModel == "Ghost_clyde") {
		return GameRepresentation::ModelType::GHOST_CLYDE;
	}
	if (strModel == "Ghost_weak") {
		return GameRepresentation::ModelType::GHOST_WEAK;
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
	if (strModel == "Door") {
		return GameRepresentation::ModelType::DOOR;
	}
	if (strModel == "Pac_gomme") {
		return GameRepresentation::ModelType::PAC_GOMME;
	}
	if (strModel == "Super_pac_gomme") {
		return GameRepresentation::ModelType::SUPER_PAC_GOMME;
	}
	if (strModel == "Fruit") {
		return GameRepresentation::ModelType::FRUIT;
	}
}

GameRepresentation::Model::Model(ModelType modelType, Utils::Orientation orientation, float shift) :
		modelType(modelType),
		orientation(orientation),
		shift(shift) {

}

GameRepresentation::Model::Model(ModelType modelType) :
		GameRepresentation::Model::Model(modelType, Utils::Orientation::SOUTH, 0)
// South is default orientation
{

}

GameRepresentation::ModelInformations::ModelInformations(const BoardPosition &position, Utils::Orientation orientation, float shift) :
		position(position),
		orientation(orientation),
		shift(shift) {

}

GameRepresentation::GameRepresentation() :
		_modelsPositions() {
	//GameRepresentation::MODELS = buildVector(); //TODO enlever
	for (auto &modelType : GameRepresentation::MODELS()) {
		_modelsPositions[modelType] = vector<ModelInformations>();
	}
}

const vector<GameRepresentation::ModelInformations> &GameRepresentation::getInformations(ModelType modelType) const {
	return _modelsPositions.at(modelType);
}

void GameRepresentation::add(Model model, const BoardPosition &position) {
	GameRepresentation::ModelInformations information(position, model.orientation, model.shift);
	_modelsPositions[model.modelType].push_back(information);
}

void GameRepresentation::remove(Model model, const BoardPosition &position) {
	vector<GameRepresentation::ModelInformations> &informations = _modelsPositions[model.modelType];
	informations.erase(std::remove_if(informations.begin(), informations.end(), [position](const GameRepresentation::ModelInformations &information) {
		return (information.position == position);
	}), informations.end());
}

const vector<GameRepresentation::ModelInformations> &GameRepresentation::operator[](ModelType modelType) const {
	return getInformations(modelType);
}
