#include <Pacman.h>

using json = nlohmann::json;

int Pacman::MAX_ITERATION = 3;

Pacman::Pacman(const BoardPosition &position, Utils::Orientation orientation) :
	_position(position),
	_orientation(orientation),
	_nextPosition(position.translate(orientation)),
	_iterPosition(0),
	_iterOrientation(0)
{

}

Pacman Pacman::fromJSON(const json &jsonPacman) {
	BoardPosition position = BoardPosition::fromJSON(jsonPacman["position"]);
	Utils::Orientation orientation = Utils::orientationFromString(jsonPacman["orientation"]);
	return Pacman(position, orientation);
}

json Pacman::toJSON() const {
	json jsonPacman;
	jsonPacman["position"] = _position.toJSON();
	jsonPacman["orientation"] = Utils::orientationToString(_orientation);
	return jsonPacman;
}

Utils::Orientation Pacman::getOrientation() const {
	return _orientation;
}

void Pacman::setOrientation(Utils::Orientation orientation) {
	_orientation = orientation;
	_iterOrientation = 0;
}

bool Pacman::orientTo(Utils::Orientation orientation) {
	if (_iterOrientation == 0) {
		_orientation = orientation;
		_iterOrientation = Pacman::MAX_ITERATION;
		_iterPosition = 0;
		return true;
	}
	return false;
}

BoardPosition Pacman::getPosition() const {
	return _position;
}

vector<BoardPosition> Pacman::getGraphicalPositions() const {
	if (_iterPosition <= Pacman::MAX_ITERATION/2) {
		return {_position};
	}
	return {_position, _position.translate(_orientation)};
}

void Pacman::setPosition(const BoardPosition &position) {
	_position = position;
	_iterPosition = 0;
	_iterOrientation = 0;
	_nextPosition = position.translate(_orientation);
}

bool Pacman::goTo(const BoardPosition &position) {
	_nextPosition = position;
	_iterPosition = (_iterPosition + 1)%Pacman::MAX_ITERATION;
	if (_iterPosition == 0) {
		_position = _nextPosition;
		return true;
	}
	return false;
}

float Pacman::getShift() const {
	return float(_iterPosition)/Pacman::MAX_ITERATION;
}

void Pacman::iterate() {
	if (_iterOrientation > 0) {
		_iterOrientation--;
	}
}

GameRepresentation::Model Pacman::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::PACMAN, _orientation, getShift());
}
