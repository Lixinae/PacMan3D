#include <Ghost.h>

#include <BoardPosition.h>

Ghost::Ghost(const BoardPosition &position, Utils::Orientation orientation): 
	_position(position),
	_orientation(orientation)
{

}

Utils::Orientation Ghost::getOrientation() {
	return _orientation;
}
	
void Ghost::setOrientation(Utils::Orientation orientation) {
	_orientation = orientation;
}
	
BoardPosition Ghost::getPosition() const {
	return _position;
}

void Ghost::setPosition(const BoardPosition & position) {
	_position = position;
}

void Ghost::iterate() {
	
}
