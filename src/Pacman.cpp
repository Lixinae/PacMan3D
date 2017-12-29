#include <Pacman.h>

using json = nlohmann::json;

int Pacman::MAX_ITERATION = 5;

Pacman::Pacman(const BoardPosition &position, Utils::Orientation orientation) :
	_position(position),
	_orientation(orientation),
	_nextPosition(position.translate(orientation)),
	_iterPosition(0)
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
	_orientation = orientation; //TODO maybe add orientTo 
}

BoardPosition Pacman::getPosition() const {
	return _position;
}

void Pacman::setPosition(const BoardPosition &position) {
	_position = position;
	_iterPosition = 0;
	_nextPosition = position.translate(_orientation);
}

void Pacman::goTo(const BoardPosition &position) {
	_nextPosition = position;
}

float Pacman::getShift() const {
	return float(_iterPosition)/Pacman::MAX_ITERATION;
}

void Pacman::move() {
	_iterPosition = (_iterPosition + 1)%Pacman::MAX_ITERATION;
	if (_iterPosition == 0) {
		_position = _nextPosition;
	}
}

void Pacman::iterate() {

}

GameRepresentation::Model Pacman::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::PACMAN, _orientation, getShift());
}
