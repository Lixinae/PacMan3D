#include <GhostInky.h>

Utils::Orientation GhostInky::getNextOrientation(const MovingContext &context) const {
	Utils::Orientation horizontal, vertical;
	BoardPosition pacmanPosition = context.pacman.getPosition();
	BoardPosition ghostPosition = getPosition();
	if (pacmanPosition.getX() < ghostPosition.getX()) {
		horizontal = Utils::Orientation::EAST;
	} else {
		horizontal = Utils::Orientation::WEST;
	}
	if (pacmanPosition.getY() < ghostPosition.getY()) {
		vertical = Utils::Orientation::SOUTH;
	} else {
		vertical = Utils::Orientation::NORTH;
	}
	vector<Utils::Orientation> walkable = context.availableOrientation();
	vector<Utils::Orientation> orientations;
	for (Utils::Orientation orientation : walkable) {
		orientations.push_back(orientation);
	}
	if (find(walkable.begin(), walkable.end(), horizontal) != walkable.end()) {
		orientations.push_back(horizontal);
	}
	if (find(walkable.begin(), walkable.end(), vertical) != walkable.end()) {
		orientations.push_back(vertical);
	}
	return Utils::randomOrientation(orientations);
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
