#include <GameInformations.h>

GameInformations::GameInformations() :
		GameInformations::GameInformations(3)
{
	
}

GameInformations::GameInformations(int lives) :
        _score(0),
        _lives(lives),
        _multiplier(1),
        _multiplierCounter(0)
{
	
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
