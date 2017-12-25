#include <BoardPosition.h>

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

BoardPosition BoardPosition::translate(Utils::Orientation orientation) const {
	int dx, dy;
	switch (orientation) {
		case Utils::Orientation::NORTH:
			dx = 0;
			dy = 1;
			break;
		case Utils::Orientation::SOUTH:
			dx = 0;
			dy = -1;
			break;
		case Utils::Orientation::EAST:
			dx = 1;
			dy = 0;
			break;
		case Utils::Orientation::WEST:
			dx = -1;
			dy = 0;
			break;
	}
	return BoardPosition(_x + dx, _y + dy);
}

glm::vec3 BoardPosition::inSpace() {
	float SQUARE_SIZE = 1; //TODO static const
	return glm::vec3(_x * SQUARE_SIZE, 0, -_y * SQUARE_SIZE);
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
