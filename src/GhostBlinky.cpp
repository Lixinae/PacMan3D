#include <GhostBlinky.h>

Utils::Orientation GhostBlinky::getNextOrientation() const {
	return Utils::randomOrientation();
}

GameRepresentation::Model GhostBlinky::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::GHOST_BLINKY, Ghost::getOrientation());
}
