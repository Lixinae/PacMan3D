#include <GameRepresentation.h>

#include <BoardPosition.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// TODO impl

const vector<GameRepresentation::Model> GameRepresentation::MODELS = {
	GameRepresentation::Model::PACMAN,
	GameRepresentation::Model::WALL,
	GameRepresentation::Model::PAC_GOMME
	//TODO SUPER_PAC_GOMME, GHOST_SPEEDY, FRUIT_CHERRY, ...
};

GameRepresentation::GameRepresentation() : _modelsPositions() {
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
