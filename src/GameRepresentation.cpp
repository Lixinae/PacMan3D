#include <GameRepresentation.h>

using namespace std;

const vector<GameRepresentation::Model> GameRepresentation::MODELS = {
        GameRepresentation::Model::PACMAN,
        GameRepresentation::Model::WALL,
        GameRepresentation::Model::FLOOR,
        GameRepresentation::Model::TUNNEL,
        GameRepresentation::Model::PAC_GOMME
        //TODO SUPER_PAC_GOMME, GHOST_SPEEDY, FRUIT_CHERRY, ...
};

//const vector<GameRepresentation::Model> GameRepresentation::MODELS = GameRepresentation::buildVector();
// Ne corrige pas le bug =/
//const vector<GameRepresentation::Model> GameRepresentation::buildVector() {
//	vector<GameRepresentation::Model> models;
//	models.push_back(GameRepresentation::Model::PACMAN);
//	models.push_back(GameRepresentation::Model::WALL);
//	models.push_back(GameRepresentation::Model::FLOOR);
//	models.push_back(GameRepresentation::Model::TUNNEL);
//	models.push_back(GameRepresentation::Model::PAC_GOMME);
//	return models;
//}


GameRepresentation::GameRepresentation() :
		_modelsPositions() {
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
