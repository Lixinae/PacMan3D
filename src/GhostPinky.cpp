#include <GhostPinky.h>

Utils::Orientation GhostPinky::getNextOrientation() const {
	return Utils::randomOrientation();
}

GameRepresentation::Model GhostPinky::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::GHOST_PINKY, Ghost::getOrientation());
}
