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

bool Tunnel::isWalkable() const {
	return true;
}
	
void Tunnel::receive(Pacman & pacman) {
	pacman.setPosition(_dest);	
	pacman.setOrientation(_destOrientation);
}
