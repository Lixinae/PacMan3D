#include <GameInformations.h>

GameInformations::GameInformations() :
		GameInformations::GameInformations(0, 3, 1, 0, 1)
{

}

GameInformations::GameInformations(int score, int lives, int multiplier, int multiplierCounter, int level) :
		_score(score),
		_lives(lives),
		_multiplier(multiplier),
		_multiplierCounter(multiplierCounter),
		_level(level)
{

}

GameInformations GameInformations::fromJSON(const json &jsonInfo) {
	return GameInformations(
			jsonInfo["score"],
			jsonInfo["lives"],
			jsonInfo["multiplier"],
			jsonInfo["multiplierCounter"],
			jsonInfo["level"]
	);
}

int GameInformations::getScore() const {
	return _score;
}

int GameInformations::getLives() const {
	return _lives;
}

int GameInformations::getMultiplier() const {
	return _multiplier;
}

bool GameInformations::isDead() const {
	return _lives == 0;
}

void GameInformations::updateScore(int value) {
	_score += value;
}

void GameInformations::updateMultipliedScore(int value) {
	_score += (value * _multiplier);
}

void GameInformations::decreaseLife() {
	if (_lives > 0) {
		_lives--;
	}
}

void GameInformations::setMultiplier(int time) {
	_multiplierCounter = time;
}

void GameInformations::increaseMultiplier() {
	_multiplier *= 2;
}

void GameInformations::iterate() {
	if (_multiplierCounter > 0) {
		_multiplierCounter--;
		if (_multiplierCounter == 0) {
			_multiplier = 1;
		}
	}
}

json GameInformations::toJSON() const {
	json jsonInfo;
	jsonInfo["score"] = _score;
	jsonInfo["lives"] = _lives;
	jsonInfo["multiplier"] = _multiplier;
	jsonInfo["multiplierCounter"] = _multiplierCounter;
	jsonInfo["level"] = _level;
	return jsonInfo;
}

void GameInformations::increaseLevel() {
	_level++;
}

int GameInformations::getLevel() const {
	return _level;
}

void GameInformations::resetScore() {
	_score = 0;
}
