#include <TimeFloor.h>

TimeFloor::TimeFloor(const Bonus *bonus, bool bonusIsPresent, int min_iter, int max_iter, int iter) : 
	_bonus(bonus->clone()),
	_bonusIsPresent(bonusIsPresent),
	_min_iter(min_iter),
	_max_iter(max_iter),
	_iter(iter)
{

}

TimeFloor::TimeFloor(const TimeFloor &other) : 
	TimeFloor(other._bonus, other._bonusIsPresent, other._min_iter, other._max_iter, other._iter)
{

}

TimeFloor::~TimeFloor() {
	delete _bonus;
}

vector<GameRepresentation::Model> TimeFloor::getModels() const {
	vector<GameRepresentation::Model> models = {GameRepresentation::Model(GameRepresentation::ModelType::FLOOR)};
	if (_bonusIsPresent && _min_iter <= _iter && _iter <= _max_iter) {
		models.push_back(_bonus->getModel());
	}
	return models;
}

bool TimeFloor::isPacmanWalkable(const BoardSquare::PacmanContext &) const {
	return true;
}

void TimeFloor::receivePacman(BoardSquare::PacmanContext &context) {
	cerr << _iter;
	if (_bonusIsPresent && _min_iter <= _iter && _iter <= _max_iter) {
		Bonus::Context bonusContext(context.ghosts, context.informations);
		_bonus->apply(bonusContext);
		_bonusIsPresent = false;
	}
}

bool TimeFloor::isGhostWalkable(const BoardSquare::GhostContext &) const {
	return true;
}

void TimeFloor::receiveGhost(BoardSquare::GhostContext &) {

}

bool TimeFloor::isDone() const {
	if (!_bonusIsPresent || !_bonus->isRequired()) {
		return true;
	}
	return false;
}

void TimeFloor::iterate() {
	if (_iter <= _max_iter) {
		_iter++;
	}
	cerr << _iter << endl;;
}

BoardSquare *TimeFloor::clone() const {
	return new TimeFloor(*this);
}

TimeFloor &TimeFloor::operator=(const TimeFloor &floor) {
	if (&floor != this) {
		TimeFloor tmp(floor);
		std::swap(_bonus, tmp._bonus);
		std::swap(_bonusIsPresent, tmp._bonusIsPresent);
		std::swap(_min_iter, tmp._min_iter);
		std::swap(_max_iter, tmp._max_iter);
		std::swap(_iter, tmp._iter);
	}
	return *this;
}

json TimeFloor::toJSON() const {
	json jsonFloor;
	jsonFloor["type"] = "time_floor";
	jsonFloor["args"]["bonus"] = _bonus->toJSON();
	jsonFloor["args"]["bonus_is_present"] = _bonusIsPresent;
	jsonFloor["args"]["min_iter"] = _min_iter;
	jsonFloor["args"]["max_iter"] = _max_iter;
	jsonFloor["args"]["iter"] = _iter;
	return jsonFloor;
}

