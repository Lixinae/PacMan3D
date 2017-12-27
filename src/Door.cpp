#include <Door.h>

Door::Door() {

}

vector<GameRepresentation::Model> Door::getModels() const {
	return {
		GameRepresentation::Model(GameRepresentation::ModelType::DOOR),
		GameRepresentation::Model(GameRepresentation::ModelType::FLOOR)
	};
}

bool Door::isPacmanWalkable(const BoardSquare::PacmanContext &) const {
	return false;
}

void Door::receivePacman(BoardSquare::PacmanContext &) {

}

bool Door::isGhostWalkable(const BoardSquare::GhostContext &) const {
	return true;
}

void Door::receiveGhost(BoardSquare::GhostContext &) {

}

BoardSquare *Door::clone() const {
	return new Door(*this);
}

json Door::toJSON() const {
	json jsonDoor;
	jsonWall["type"] = "wall";
	jsonWall["args"] = {};
	return jsonDoor;
}
