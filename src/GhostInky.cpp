#include <GhostInky.h>

Utils::Orientation GhostInky::getNextOrientation() const {
	return Utils::randomOrientation();
}

GameRepresentation::Model GhostInky::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::GHOST_INKY, Ghost::getOrientation());
}

Ghost * GhostInky::clone() const {
	return new GhostInky(Ghost::getPosition(), Ghost::getOrientation());
}
