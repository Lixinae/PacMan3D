#include <GameInformations.h>

GameInformations::GameInformations() :
		GameInformations::GameInformations(0, 10000, 10000, 3, 1, 0, 1)
{

}

GameInformations::GameInformations(int score, int score_max_life, int step_score_max_life, int lives, int multiplier, int multiplierCounter, int level) :
		_score(score),
		_score_init(score),
		_score_max_life(score_max_life),
		_step_score_max_life(step_score_max_life),
		_lives(lives),
		_multiplier(multiplier),
		_multiplierCounter(multiplierCounter),
		_level(level)
{

}

GameInformations GameInformations::fromJSON(const json &jsonInfo) {
	return GameInformations(
			jsonInfo["score"],
			jsonInfo["score_max_life"],
			jsonInfo["step_score_max_life"],
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

bool GameInformations::isDead() const {
	return _lives == 0;
}

void GameInformations::addLifeScore() {
	if (_score > _score_max_life) {
		_lives++;
		_score_max_life += _step_score_max_life;
	}
}

void GameInformations::updateScore(int value) {
	_score += value;
	addLifeScore();
}

void GameInformations::updateMultipliedScore(int value) {
	_score += (value * _multiplier);
	addLifeScore();
}

void GameInformations::decreaseLife() {
	if (_lives > 0) {
		_lives--;
	}
}

void GameInformations::setMultiplierCounter(int time) {
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
	jsonInfo["score_max_life"] = _score_max_life;
	jsonInfo["step_score_max_life"] = _step_score_max_life;
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
