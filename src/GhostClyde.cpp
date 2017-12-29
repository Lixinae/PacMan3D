#include <GhostClyde.h>

Utils::Orientation GhostClyde::getNextOrientation(const MovingContext & context) const {
	return Utils::randomOrientation(context.availableOrientation);
}

GameRepresentation::ModelType GhostClyde::getModelType() const {
	return GameRepresentation::ModelType::GHOST_CLYDE;
}

Ghost *GhostClyde::clone() const {
	return new GhostClyde(Ghost::getPosition(), Ghost::getOrientation());
}

json GhostClyde::toJSON() const {
	json jsonGhost;
	jsonGhost["type"] = "clyde";
	jsonGhost["position"] = getPosition().toJSON();
	jsonGhost["orientation"] = Utils::orientationToString(getOrientation());
	return jsonGhost;
}
