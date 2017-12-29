#include <Ghost.h>

#include <GhostBlinky.h>
#include <GhostPinky.h>
#include <GhostInky.h>
#include <GhostClyde.h>

int Ghost::CASE_REDIRECTION = 2;
int Ghost::MAX_ITERATION = 3;

Ghost::MovingContext::MovingContext(vector<Utils::Orientation> &availableOrientation):
		availableOrientation(availableOrientation)
{
	
}

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
		_iterOrientation(0),
		_weakCounter(),
		_crossDoor(true)
{

}

Utils::Orientation Ghost::getOrientation() const {
	return _orientation;
}

void Ghost::setOrientation(Utils::Orientation orientation) {
	_iterOrientation = 0;
	_orientation = orientation;
}

bool Ghost::orientTo(Utils::Orientation orientation) {
	if (_iterOrientation == 0) {
		_orientation = orientation;
		_iterOrientation = Ghost::CASE_REDIRECTION*Ghost::MAX_ITERATION;
		_iterPosition = 0;
		return true;
	}
	return false;
}

BoardPosition Ghost::getPosition() const {
	return _position;
}

void Ghost::setPosition(const BoardPosition &position) {
	_position = position;
	_iterPosition = 0;
	_iterOrientation = 0;
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

bool Ghost::goTo(const BoardPosition &position) {
	_nextPosition = position;
	_iterPosition = (_iterPosition + 1)%Ghost::MAX_ITERATION;
	if (_iterPosition == 0) {
		_position = _nextPosition;
		return true;
	}
	return false;
}

float Ghost::getShift() const {
	return float(_iterPosition)/Ghost::MAX_ITERATION;
}
	

void Ghost::iterate() {
	if (_weakCounter > 0) {
		_weakCounter--;
	}
	/*_iterOrientation = (_iterOrientation + 1) % (Ghost::CASE_REDIRECTION*Ghost::MAX_ITERATION);
	if (_iterOrientation == 0) {
		_orientation = getNextOrientation();
	}*/
	if (_iterOrientation > 0) {
		_iterOrientation--;
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
