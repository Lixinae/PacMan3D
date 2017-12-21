#include <Ghost.h>

#include <BoardPosition.h>

Ghost::Ghost(const BoardPosition &position, Utils::Orientation orientation): 
	_position(position),
	_orientation(orientation),
	_count()
{

}

Utils::Orientation Ghost::getOrientation() const {
	return _orientation;
}
	
BoardPosition Ghost::getPosition() const {
	return _position;
}

void Ghost::setPosition(const BoardPosition & position) {
	_position = position;
}

void Ghost::iterate() {
	_count = (_count + 1)%3;
	if (_count == 0) {
		_orientation = getNextOrientation();
	}
}
