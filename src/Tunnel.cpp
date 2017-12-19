#include <Tunnel.h>

Tunnel::Tunnel(Utils::Orientation orientation, const BoardPosition & dest, Utils::Orientation destOrientation) : 
	_orientation(orientation),
	_dest(dest),
	_destOrientation(destOrientation)
{

}
	
vector<GameRepresentation::Model> Tunnel::getModels() const {
	GameRepresentation::Model modelTunel;
	// TODO use different model in function of orientation
	switch (_orientation) {
		case Utils::Orientation::NORTH:
			modelTunel = GameRepresentation::Model::TUNNEL;
			break;
		case Utils::Orientation::SOUTH:
			modelTunel = GameRepresentation::Model::TUNNEL;
			break;
		case Utils::Orientation::EAST:
			modelTunel = GameRepresentation::Model::TUNNEL;
			break;
		case Utils::Orientation::WEST:
			modelTunel = GameRepresentation::Model::TUNNEL;
			break;
	}
	return {modelTunel};
}

bool Tunnel::isPacmanWalkable(const BoardSquare::PacmanContext &) const {
	return true;
}
	
void Tunnel::receivePacman(BoardSquare::PacmanContext & context) {
	context.pacman.setPosition(_dest.translate(_destOrientation));	
	context.pacman.setOrientation(_destOrientation);
}

BoardSquare * Tunnel::clone() {
	return new Tunnel(*this);
}
