#include <Tunnel.h>

Tunnel::Tunnel(Utils::Orientation orientation, const BoardPosition &dest, Utils::Orientation destOrientation) :
		_orientation(orientation),
		_dest(dest),
		_destOrientation(destOrientation) {

}

vector<GameRepresentation::Model> Tunnel::getModels() const {
	GameRepresentation::ModelType modelTunel;
	// TODO use orientation for orient Model
	switch (_orientation) {
		case Utils::Orientation::NORTH:
			modelTunel = GameRepresentation::ModelType::TUNNEL;
			break;
		case Utils::Orientation::SOUTH:
			modelTunel = GameRepresentation::ModelType::TUNNEL;
			break;
		case Utils::Orientation::EAST:
			modelTunel = GameRepresentation::ModelType::TUNNEL;
			break;
		case Utils::Orientation::WEST:
			modelTunel = GameRepresentation::ModelType::TUNNEL;
			break;
	}
	return {GameRepresentation::Model(modelTunel)};
}

bool Tunnel::isPacmanWalkable(const BoardSquare::PacmanContext &) const {
	return true;
}

void Tunnel::receivePacman(BoardSquare::PacmanContext &context) {
	context.pacman.setPosition(_dest.translate(_destOrientation));
	context.pacman.setOrientation(_destOrientation);
}

bool Tunnel::isGhostWalkable(const BoardSquare::GhostContext &) const {
	return true;
}

void Tunnel::receiveGhost(BoardSquare::GhostContext &context) {
	context.ghost.setPosition(_dest.translate(_destOrientation));
	context.ghost.setOrientation(_destOrientation);
}

bool Tunnel::isDone() const {
	return true;
}

BoardSquare *Tunnel::clone() const {
	return new Tunnel(*this);
}

json Tunnel::toJSON() const {
	json jsonTunnel;
	jsonTunnel["type"] = "tunnel";
	jsonTunnel["args"]["orientation"] = Utils::orientationToString(_orientation);
	jsonTunnel["args"]["dest"] = _dest.toJSON();
	jsonTunnel["args"]["destOrientation"] = Utils::orientationToString(_destOrientation);
	return jsonTunnel;
}

