#include <GhostInky.h>

Utils::Orientation GhostInky::getNextOrientation(const MovingContext & context) const {
	return Utils::randomOrientation(context.availableOrientation());
}

GameRepresentation::ModelType GhostInky::getModelType() const {
	return GameRepresentation::ModelType::GHOST_INKY;
}

Ghost *GhostInky::clone() const {
	return new GhostInky(Ghost::getPosition(), Ghost::getOrientation());
}

json GhostInky::toJSON() const {
	json jsonGhost;
	jsonGhost["type"] = "inky";
	jsonGhost["position"] = getPosition().toJSON();
	jsonGhost["orientation"] = Utils::orientationToString(getOrientation());
	return jsonGhost;
}
