#include <Wall.h>

Wall::Wall() {

}

vector<GameRepresentation::Model> Wall::getModels() const {
	return {GameRepresentation::Model(GameRepresentation::ModelType::WALL)};
}

bool Wall::isPacmanWalkable(const BoardSquare::PacmanContext &) const {
	return false;
}

void Wall::receivePacman(BoardSquare::PacmanContext &) {

}

bool Wall::isGhostWalkable(const BoardSquare::GhostContext &) const {
	return false;
}

void Wall::receiveGhost(BoardSquare::GhostContext &) {

}

bool Wall::isDone() const {
	return true;
}

void Wall::iterate() {
	
}

BoardSquare *Wall::clone() const {
	return new Wall(*this);
}

json Wall::toJSON() const {
	json jsonWall;
	jsonWall["type"] = "wall";
	jsonWall["args"] = {};
	return jsonWall;
}
