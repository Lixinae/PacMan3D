#include "boardRepresentation.h"

#include "boardPosition.h"
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// TODO impl

const vector<BoardRepresentation::Model> BoardRepresentation::MODELS = {
	BoardRepresentation::Model::PACMAN,
	BoardRepresentation::Model::WALL,
	BoardRepresentation::Model::PAC_GOMME
	//TODO SUPER_PAC_GOMME, GHOST_SPEEDY, FRUIT_CHERRY, ...
};

BoardRepresentation::BoardRepresentation() : modelsPositions() {
	for (auto & model : BoardRepresentation::MODELS) {  
		modelsPositions[model] = vector<BoardPosition>();
	}
}
	
const vector<BoardPosition> & BoardRepresentation::getPositions(Model model) const {
	return modelsPositions.at(model);
}

void BoardRepresentation::add(Model model, const BoardPosition & position) {
	modelsPositions[model].push_back(position);
}
	
void BoardRepresentation::remove(Model model, const BoardPosition & position) {
	vector<BoardPosition> positions = modelsPositions[model];	
	positions.erase(std::remove(positions.begin(), positions.end(), position), positions.end());
}
	
const vector<BoardPosition> & BoardRepresentation::operator[](Model model) const {
	return getPositions(model);
}
