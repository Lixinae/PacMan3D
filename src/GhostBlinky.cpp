#include <GhostBlinky.h>

GameRepresentation::Model GhostBlinky::getModel() {
	return GameRepresentation::Model(GameRepresentation::ModelType::GHOST_BLINKY, Ghost::getOrientation());
}
