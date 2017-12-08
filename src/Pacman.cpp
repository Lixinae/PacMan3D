#include <Pacman.h>

#include <BoardPosition.h>
#include <json/json.hpp>

using json = nlohmann::json;

Pacman::Pacman(const BoardPosition & position, Orientation orientation) : _position(position), _orientation(orientation) {

}

Pacman Pacman::fromJSON(json jsonPacman) {
	BoardPosition position = BoardPosition::fromJSON(jsonPacman["position"]);
	Orientation orientation = orientationFromString(jsonPacman["orientation"]); 
	return Pacman(position, orientation);
}

void Pacman::setOrientation(Orientation orientation) {
	_orientation = orientation;
}

void Pacman::iterate() {
	int dx, dy;
	switch (_orientation) {
		case Orientation::NORTH:
			dx = 0;
			dy = 1;
			break;
		case Orientation::SOUTH:
			dx = 0;
			dy = -1;
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
	_position = BoardPosition(_position.getX() + dx, _position.getY() + dy);
}


BoardPosition Pacman::getPosition() const {
	return _position;
}

BoardPosition Pacman::getNextPosition() const {
	int dx, dy;
	switch (_orientation) {
		case Orientation::NORTH:
			dx = 0;
			dy = 1;
			break;
		case Orientation::SOUTH:
			dx = 0;
			dy = -1;
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

Pacman::Orientation Pacman::orientationFromString(string strOrientation) {
	if (strOrientation == "north") {
		return Pacman::Orientation::NORTH;
	}
	if (strOrientation == "south") {
		return Pacman::Orientation::SOUTH;
	}
	if (strOrientation == "east") {
		return Pacman::Orientation::EAST;
	}
	if (strOrientation == "west") {
		return Pacman::Orientation::WEST;
	} 
	throw invalid_argument(strOrientation + " is not a valid string representation of orientation");
}
