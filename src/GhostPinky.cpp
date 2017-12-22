#include <GhostPinky.h>

Utils::Orientation GhostPinky::getNextOrientation() const {
	return Utils::randomOrientation();
}

GameRepresentation::Model GhostPinky::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::GHOST_PINKY, Ghost::getOrientation());
}

Ghost * GhostPinky::clone() const {
	return new GhostPinky(Ghost::getPosition(), Ghost::getOrientation());
}
