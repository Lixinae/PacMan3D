#include <BoardPosition.h>

#include <iostream>
#include <json/json.hpp>

using namespace std;

using json = nlohmann::json;

BoardPosition::BoardPosition(int x, int y) : _x(x), _y(y) {

}

BoardPosition BoardPosition::fromJSON(const json & jsonPosition) {
	return BoardPosition(jsonPosition["x"], jsonPosition["y"]);
};

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
	return !(*this == other);
}

bool BoardPosition::operator<(const BoardPosition & other) const {
	if (_x == other._x) {
		return (_y < other._y);
	}
	return (_x < other._x);
}

bool BoardPosition::operator>(const BoardPosition & other) const {
	if (_x == other._x) {
		return (_y > other._y);
	}
	return (_x > other._x);
}

bool BoardPosition::operator<=(const BoardPosition & other) const {
	return ((*this < other) || (*this == other));
}

bool BoardPosition::operator>=(const BoardPosition & other) const {
	return ((*this > other) || (*this == other));
}

ostream & operator<<(ostream & os, BoardPosition position) {
	return (os << "(" << position._x << ", " << position._y << ")");
}
