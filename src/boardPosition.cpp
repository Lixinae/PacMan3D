#include "boardPosition.h"

#include <iostream>

using namespace std;

BoardPosition::BoardPosition(int x, int y) : _x(x), _y(y) {

}

int BoardPosition::getX() const {
	return _x;
}

int BoardPosition::getY() const {
	return _y;
}

bool BoardPosition::operator==(const BoardPosition & other) const {
	return (_x == other._x && _y == other._y);
}

bool BoardPosition::operator!=(const BoardPosition & other) const {
	return not (*this == other);
}

ostream & operator<<(ostream & os, BoardPosition position) {
	return (os << "(" << position._x << ", " << position._y << ")");
}
