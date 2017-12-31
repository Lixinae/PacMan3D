#include <GhostBlinky.h>

Utils::Orientation GhostBlinky::getNextOrientation(const MovingContext & context) const {
	return Utils::randomOrientation(context.availableOrientation());
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
