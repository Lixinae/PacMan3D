#include <Ghost.h>

#include <GhostBlinky.h>
#include <GhostPinky.h>
#include <GhostInky.h>
#include <GhostClyde.h>

int Ghost::MAX_ITERATION = 5;

Ghost *Ghost::fromJSON(const json &jsonGhost) {
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

Ghost::Ghost(const BoardPosition &position, Utils::Orientation orientation) :
		_position(position),
		_orientation(orientation),
		_nextPosition(position.translate(orientation)),
		_iterPosition(0),
		_weakCounter(),
		_count(),
		_crossDoor(true)
{

}

Utils::Orientation Ghost::getOrientation() const {
	return _orientation;
}

void Ghost::setOrientation(Utils::Orientation orientation) {
	_count = 0;
	_orientation = orientation;
}

BoardPosition Ghost::getPosition() const {
	return _position;
}

void Ghost::setPosition(const BoardPosition &position) {
	_position = position;
	_iterPosition = 0;
	_nextPosition = position.translate(_orientation);
}

bool Ghost::isWeak() const {
	return (_weakCounter > 0);
}

void Ghost::setWeak(int time) {
	_weakCounter = time;
}

bool Ghost::canCrossDoor() {
	return _crossDoor;
}
	
void Ghost::crossDoor() {
	_crossDoor = false;
}

void Ghost::goTo(const BoardPosition &position) {
	_nextPosition = position;
}

float Ghost::getShift() const {
	return float(_iterPosition)/Ghost::MAX_ITERATION;
}
	
void Ghost::move() {
	_iterPosition = (_iterPosition + 1)%Ghost::MAX_ITERATION;
	if (_iterPosition == 0) {
		_position = _nextPosition;
	}
}

void Ghost::iterate() {
	if (_weakCounter > 0) {
		_weakCounter--;
	}

	_count = (_count + 1) % Ghost::MAX_ITERATION;
	if (_count == 0) {
		_orientation = getNextOrientation();
	}
}

GameRepresentation::Model Ghost::getModel() const {
	GameRepresentation::ModelType modelType;
	if (isWeak()) {
		modelType = GameRepresentation::ModelType::GHOST_WEAK;
	} else {
		modelType = getModelType();
	}
	return GameRepresentation::Model(modelType, getOrientation(), getShift());
}
