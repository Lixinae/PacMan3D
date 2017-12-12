#include <Pacman.h>

#include <BoardPosition.h>
#include <json/json.hpp>

using json = nlohmann::json;

Pacman::Pacman(const BoardPosition & position, Utils::Orientation orientation) : _position(position), _orientation(orientation) {

}

Pacman Pacman::fromJSON(const json & jsonPacman) {
	BoardPosition position = BoardPosition::fromJSON(jsonPacman["position"]);
	Utils::Orientation orientation = Utils::orientationFromString(jsonPacman["orientation"]); 
	return Pacman(position, orientation);
}

void Pacman::setOrientation(Utils::Orientation orientation) {
	_orientation = orientation;
}

BoardPosition Pacman::getPosition() const {
	return _position;
}

BoardPosition Pacman::getNextPosition() const {
	return _position.translate(_orientation);
}

void Pacman::setNextPosition() {
	_position = _position.translate(_orientation);
}

GameRepresentation::Model Pacman::getModel() const {
	return GameRepresentation::Model::PACMAN;
}
