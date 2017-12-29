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

bool Door::isGhostWalkable(const BoardSquare::GhostContext & context) const {
	return context.ghost.canCrossDoor();
}

void Door::receiveGhost(BoardSquare::GhostContext & context) {
	context.ghost.crossDoor();
	context.ghost.setPosition(context.ghost.getPosition().translate(context.ghost.getOrientation()));
}

bool Door::isDone() const {
	return true;
}

BoardSquare *Door::clone() const {
	return new Door(*this);
}

json Door::toJSON() const {
	json jsonDoor;
	jsonDoor["type"] = "door";
	jsonDoor["args"] = {};
	return jsonDoor;
}
