#include <Floor.h>

#include <Pacman.h>
#include <BoardSquare.h>
#include <Bonus.h>
#include <GameRepresentation.h>

Floor::Floor() : _bonus(nullptr) {

}

Floor::Floor(const Bonus * bonus) : _bonus(bonus->clone()) {

}

Floor::Floor(const Floor & other) : _bonus(nullptr) {
	if (other._bonus != nullptr) {
		_bonus = other._bonus->clone();
	}
}

Floor::~Floor() {
	if (_bonus != nullptr) {
		delete _bonus;
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
	
void Floor::receive(BoardSquare::Context & context) {
	if (_bonus != nullptr) {
		//_bonus->apply(pacman);
		_bonus->apply(context.pacman);
		delete _bonus;
		_bonus = nullptr;
	}
}
	
BoardSquare * Floor::clone() {
	return new Floor(*this);
}

Floor & Floor::operator=(const Floor & floor) {
	if (&floor != this) {
		Floor tmp(floor);
		std::swap(_bonus, tmp._bonus);
	}
	return *this;
}
