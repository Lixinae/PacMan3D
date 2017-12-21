#include <GhostInky.h>

GameRepresentation::Model GhostInky::getModel() {
	return GameRepresentation::Model(GameRepresentation::ModelType::GHOST_INKY, Ghost::getOrientation());
}
