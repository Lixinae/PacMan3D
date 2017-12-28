#include <Pacman.h>

using json = nlohmann::json;

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
	_orientation = orientation;
}

BoardPosition Pacman::getPosition() const {
	return _position;
}

void Pacman::setPosition(const BoardPosition &position) {
	//_position = position;
	_nextPosition = position;
}

void Pacman::iterate() {
	int max = 3;
	_iterPosition = (_iterPosition + 1)%max;
	if (_iterPosition == 0) {
		_position = _nextPosition;
	}
}

GameRepresentation::Model Pacman::getModel() const {
	return GameRepresentation::Model(GameRepresentation::ModelType::PACMAN, _orientation);
}
