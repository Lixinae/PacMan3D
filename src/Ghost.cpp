#include <Ghost.h>

#include <GhostBlinky.h>
#include <GhostPinky.h>
#include <GhostInky.h>
#include <GhostClyde.h>

int Ghost::MAX_ITERATION = 3;
int Ghost::CASE_REDIRECTION_ITERATION = 2 * Ghost::MAX_ITERATION;

Ghost::MovingContext::MovingContext(
		Pacman &pacman,
		function<vector<Utils::Orientation>()> &availableOrientation,
		function<Utils::Orientation()> &orientationOnPacman,
		function<Utils::Orientation()> &orientationBlockPacman,
		function<Utils::Orientation()> &orientationAvoidPacman
) :
		pacman(pacman),
		availableOrientation(availableOrientation),
		orientationOnPacman(orientationOnPacman),
		orientationBlockPacman(orientationBlockPacman),
		orientationAvoidPacman(orientationAvoidPacman) {

}

Ghost *Ghost::fromJSON(const json &jsonGhost) {
	BoardPosition position = BoardPosition::fromJSON(jsonGhost["position"]);
	Utils::Orientation orientation = Utils::orientationFromString(jsonGhost["orientation"]);
	string type = jsonGhost["type"];
	if (type == "blinky") {
		return new GhostBlinky(position, orientation);
	}
	if (type == "pinky") {
		return new GhostPinky(position, orientation);
	}
	if (type == "inky") {
		return new GhostInky(position, orientation);
	}
	if (type == "clyde") {
		return new GhostClyde(position, orientation);
	}
	throw invalid_argument(type + " is not a valid string representation of ghost type");
}

Ghost::Ghost(const BoardPosition &position, Utils::Orientation orientation) :
		_position(position),
		_orientation(orientation),
		_nextPosition(position.translate(orientation)),
		_iterPosition(0),
		_iterOrientation(0),
		_weakCounter(),
		_crossDoor(false) {

}

Utils::Orientation Ghost::getOrientation() const {
	return _orientation;
}

void Ghost::setOrientation(Utils::Orientation orientation) {
	_iterOrientation = 0;
	_orientation = orientation;
}

bool Ghost::orientToTarget(const MovingContext &context) {
	if (_iterOrientation != 0) {
		return false;
	}
	if (!_crossDoor) {
		_orientation = Utils::randomOrientation(context.availableOrientation());
	} else if (isWeak()) {
		_orientation = context.orientationAvoidPacman();
	} else {
		_orientation = getNextOrientation(context);
	}
	_iterOrientation = Ghost::CASE_REDIRECTION_ITERATION;
	_iterPosition = 0;
	return true;
}

BoardPosition Ghost::getPosition() const {
	return _position;
}

vector<BoardPosition> Ghost::getGraphicalPositions() const {
	if (_iterPosition <= Ghost::MAX_ITERATION / 2) {
		return {_position};
	}
	return {_position, _position.translate(_orientation)};
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
	return !_crossDoor;
}

void Ghost::crossDoor() {
	_crossDoor = true;
}

bool Ghost::goTo(const BoardPosition &position) {
	_nextPosition = position;
	_iterPosition = (_iterPosition + 1) % Ghost::MAX_ITERATION;
	if (_iterPosition == 0) {
		_position = _nextPosition;
		return true;
	}
	return false;
}

float Ghost::getShift() const {
	return float(_iterPosition) / Ghost::MAX_ITERATION;
}


void Ghost::iterate() {
	if (_weakCounter > 0) {
		_weakCounter--;
	}
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
