#include <Floor.h>

#include <Pacman.h>
#include <BoardSquare.h>
#include <Bonus.h>
#include <GameRepresentation.h>
#include <PacGomme.h>//TODO remove

Floor::Floor() : _bonus(new PacGomme()) { //TODO

}

Floor::Floor(const Floor & other) : _bonus(other._bonus) { // TODO : deep copy, add clone() in interface bonus

}

Floor::~Floor() {
	if (_bonus != nullptr) {
		// TODO delete bonus, or, bonus.delete() in interface
	}
}
	
vector<GameRepresentation::Model> Floor::getModels() const {
	vector<GameRepresentation::Model> models = {GameRepresentation::Model::FLOOR};
	if (_bonus != nullptr) {
		models.push_back(_bonus->getModel());
	}
	return models;
}

bool Floor::isWalkable() const {
	return true;
}
	
void Floor::receive(Pacman pacman) {
	if (_bonus != nullptr) {
		_bonus->apply(pacman);
		// TODO delete bonus, or, bonus.delete() in interface
		_bonus = nullptr;
	}
}

Floor & Floor::operator=(const Floor & floor) {
	if (&floor != this) {
		Floor tmp(floor);
		std::swap(_bonus, tmp._bonus);
	}
	return *this;
}
