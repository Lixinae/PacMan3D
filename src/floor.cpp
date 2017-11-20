#include "floor.h"

#include "pacman.h"
#include "boardSquare.h"

Floor::Floor() : _bonus(nullptr) {

}

Floor::Floor(const Floor & other) : _bonus(other._bonus) { // TODO : deep copy, add clone() in interface bonus

}

Floor::~Floor() {
	if (_bonus != nullptr) {
		// TODO delete bonus, or, bonus.delete() in interface
	}
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
