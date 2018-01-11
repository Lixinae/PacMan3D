#include <Tunnel.h>

Tunnel::Tunnel(Utils::Orientation orientation, const BoardPosition &dest, Utils::Orientation destOrientation) :
		_orientation(orientation),
		_dest(dest),
		_destOrientation(destOrientation) {

}

vector<GameRepresentation::Model> Tunnel::getModels() const {
	return {GameRepresentation::Model(GameRepresentation::ModelType::TUNNEL, _orientation, 0)};
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

void Tunnel::iterate() {

}

BoardPosition Tunnel::neighbour(const BoardPosition &position, Utils::Orientation orientation) {
	if (_orientation == orientation) {
		return _dest;
	}
	return BoardSquare::neighbour(position, orientation);
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

