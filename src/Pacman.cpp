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

Utils::Orientation Pacman::getOrientation() {
	return _orientation;
}

void Pacman::setOrientation(Utils::Orientation orientation) {
	_orientation = orientation;
}

BoardPosition Pacman::getPosition() const {
	return _position;
}

void Pacman::setPosition(const BoardPosition & position) {
	_position = position;
}

void Pacman::iterate() {
	// TODO decrement counter when super state ect
}

GameRepresentation::ModelType Pacman::getModel() const {
	return GameRepresentation::ModelType::PACMAN;
}
