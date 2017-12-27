#include <GhostBlinky.h>

Utils::Orientation GhostBlinky::getNextOrientation() const {
	return Utils::randomOrientation();
}

GameRepresentation::ModelType GhostBlinky::getModelType() const {
	return GameRepresentation::ModelType::GHOST_BLINKY;
}

Ghost *GhostBlinky::clone() const {
	return new GhostBlinky(Ghost::getPosition(), Ghost::getOrientation());
}

json GhostBlinky::toJSON() const {
	json jsonGhost;
	jsonGhost["type"] = "blinky";
	jsonGhost["position"] = getPosition().toJSON();
	jsonGhost["orientation"] = Utils::orientationToString(getOrientation());
	return jsonGhost;
}
