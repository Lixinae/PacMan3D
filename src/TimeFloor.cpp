#include <TimeFloor.h>

TimeFloor::TimeFloor(const Bonus *bonus) : _bonus(bonus->clone()) {

}

TimeFloor::TimeFloor(const TimeFloor &other) : _bonus(other._bonus->clone()) {

}

TimeFloor::~TimeFloor() {
	delete _bonus;
}

vector<GameRepresentation::Model> TimeFloor::getModels() const {
	vector<GameRepresentation::Model> models = {GameRepresentation::Model(GameRepresentation::ModelType::FLOOR)};
	if (_bonus != nullptr) {
		models.push_back(_bonus->getModel());
	}
	return models;
}

bool TimeFloor::isPacmanWalkable(const BoardSquare::PacmanContext &) const {
	return true;
}

void TimeFloor::receivePacman(BoardSquare::PacmanContext &context) {
	if (_bonus != nullptr) {
		Bonus::Context bonusContext(context.ghosts, context.informations);
		_bonus->apply(bonusContext);
		delete _bonus;
		_bonus = nullptr;
	}
}

bool TimeFloor::isGhostWalkable(const BoardSquare::GhostContext &) const {
	return true;
}

void TimeFloor::receiveGhost(BoardSquare::GhostContext &) {

}

bool TimeFloor::isDone() const {
	if (_bonus == nullptr || !_bonus->isRequired()) {
		return true;
	}
	return false;
}

BoardSquare *TimeFloor::clone() const {
	return new TimeFloor(*this);
}

TimeFloor &TimeFloor::operator=(const TimeFloor &floor) {
	if (&floor != this) {
		TimeFloor tmp(floor);
		std::swap(_bonus, tmp._bonus);
	}
	return *this;
}

json TimeFloor::toJSON() const {
	json jsonFloor;
	jsonFloor["type"] = "floor";
	if (_bonus == nullptr) {
		jsonFloor["args"]["bonus"] = nullptr;
	} else {
		jsonFloor["args"]["bonus"] = _bonus->toJSON();
	}
	return jsonFloor;
}

