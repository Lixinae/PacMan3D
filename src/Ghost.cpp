#include <Ghost.h>

#include <BoardPosition.h>
#include <GhostBlinky.h>
#include <GhostPinky.h>
#include <GhostInky.h>
#include <GhostClyde.h>

Ghost * Ghost::fromJSON(const json & jsonGhost) {
	BoardPosition position = BoardPosition::fromJSON(jsonGhost["position"]);
	Utils::Orientation orientation = Utils::orientationFromString(jsonGhost["orientation"]);
	if (jsonGhost["type"] == "blinky") {
		return new GhostBlinky(position, orientation);
	}
	if (jsonGhost["type"] == "pinky") {
		return new GhostPinky(position, orientation);
	}
	if (jsonGhost["type"] == "inky") {
		return new GhostInky(position, orientation);
	}
	if (jsonGhost["type"] == "clyde") {
		return new GhostClyde(position, orientation);
	}
}

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
