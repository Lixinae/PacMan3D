#include <GhostPinky.h>

Utils::Orientation GhostPinky::getNextOrientation() const {
	return Utils::randomOrientation();
}

GameRepresentation::ModelType GhostPinky::getModelType() const {
	return GameRepresentation::ModelType::GHOST_PINKY;
}

Ghost *GhostPinky::clone() const {
	return new GhostPinky(Ghost::getPosition(), Ghost::getOrientation());
}
