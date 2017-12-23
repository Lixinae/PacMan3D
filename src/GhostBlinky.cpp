#include <GhostBlinky.h>

Utils::Orientation GhostBlinky::getNextOrientation() const {
	return Utils::randomOrientation();
}

GameRepresentation::ModelType GhostBlinky::getModelType() const {
	return GameRepresentation::ModelType::GHOST_BLINKY;
}

Ghost * GhostBlinky::clone() const {
	return new GhostBlinky(Ghost::getPosition(), Ghost::getOrientation());
}
