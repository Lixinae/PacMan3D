#include <GhostClyde.h>

GameRepresentation::Model GhostClyde::getModel() {
	return GameRepresentation::Model(GameRepresentation::ModelType::GHOST_CLYDE, Ghost::getOrientation());
}
