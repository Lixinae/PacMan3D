#include <Pacman.h>

#include <BoardPosition.h>

Pacman::Pacman(const BoardPosition & position, Orientation orientation) : _position(position), _orientation(orientation) {

}

void Pacman::setOrientation(Orientation orientation) {
	_orientation = orientation;
}

BoardPosition Pacman::getPosition() const {
	return _position;
}

BoardPosition Pacman::getNextPosition() const {
	int dx, dy;
	switch (_orientation) {
		case Orientation::NORTH:
			dx = 0;
			dy = -1;
			break;
		case Orientation::SOUTH:
			dx = 0;
			dy = 1;
			break;
		case Orientation::EAST:
			dx = 1;
			dy = 0;
			break;
		case Orientation::WEST:
			dx = -1;
			dy = 0;
			break;
	}
	return BoardPosition(_position.getX() + dx, _position.getY() + dy);
}

void Pacman::setNextPosition(const BoardPosition & position) {
	_position = position;
} 

