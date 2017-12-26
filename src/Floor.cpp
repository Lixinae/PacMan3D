#include <Floor.h>

Floor::Floor() : _bonus(nullptr) {

}

Floor::Floor(const Bonus *bonus) : _bonus(bonus->clone()) {

}

Floor::Floor(const Floor &other) : _bonus(nullptr) {
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
	vector<GameRepresentation::Model> models = {GameRepresentation::Model(GameRepresentation::ModelType::FLOOR)};
	if (_bonus != nullptr) {
		models.push_back(_bonus->getModel());
	}
	return models;
}

bool Floor::isPacmanWalkable(const BoardSquare::PacmanContext &) const {
	return true;
}

void Floor::receivePacman(BoardSquare::PacmanContext &context) {
	if (_bonus != nullptr) {
		Bonus::Context bonusContext(context.ghosts, context.informations);
		_bonus->apply(bonusContext);
		delete _bonus;
		_bonus = nullptr;
	}
}

bool Floor::isGhostWalkable(const BoardSquare::GhostContext &) const {
	return true;
}

void Floor::receiveGhost(BoardSquare::GhostContext &) {

}

BoardSquare *Floor::clone() {
	return new Floor(*this);
}

Floor &Floor::operator=(const Floor &floor) {
	if (&floor != this) {
		Floor tmp(floor);
		std::swap(_bonus, tmp._bonus);
	}
	return *this;
}
