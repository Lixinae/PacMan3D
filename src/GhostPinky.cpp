#include <GhostPinky.h>

Utils::Orientation GhostPinky::getNextOrientation(const MovingContext & context) const {
	return Utils::randomOrientation(context.availableOrientation());
}

GameRepresentation::ModelType GhostPinky::getModelType() const {
	return GameRepresentation::ModelType::GHOST_PINKY;
}

Ghost *GhostPinky::clone() const {
	return new GhostPinky(Ghost::getPosition(), Ghost::getOrientation());
}

json GhostPinky::toJSON() const {
	json jsonGhost;
	jsonGhost["type"] = "pinky";
	jsonGhost["position"] = getPosition().toJSON();
	jsonGhost["orientation"] = Utils::orientationToString(getOrientation());
	return jsonGhost;
}
