#include <GhostInky.h>

Utils::Orientation GhostInky::getNextOrientation() const {
	return Utils::randomOrientation();
}

GameRepresentation::ModelType GhostInky::getModelType() const {
	return GameRepresentation::ModelType::GHOST_INKY;
}

Ghost * GhostInky::clone() const {
	return new GhostInky(Ghost::getPosition(), Ghost::getOrientation());
}
