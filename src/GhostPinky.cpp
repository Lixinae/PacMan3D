#include <GhostPinky.h>

GameRepresentation::Model GhostPinky::getModel() {
	return GameRepresentation::Model(GameRepresentation::ModelType::GHOST_PINKY, Ghost::getOrientation());
}
