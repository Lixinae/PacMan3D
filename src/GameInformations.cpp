#include <GameInformations.h>

GameInformations::GameInformations() :
        _score(0),
        _lives(3),
        _multiplier(1) {
}

GameInformations::GameInformations(int lives) :
        _score(0),
        _lives(lives),
        _multiplier(1) {}

int GameInformations::get_score() const {
    return _score;
}

int GameInformations::get_lives() const {
    return _lives;
}

int GameInformations::get_multiplier() const {
    return _multiplier;
}

bool GameInformations::isDead() const {
    return _lives == 0;
}

void GameInformations::updateScore(int value) {
    _score += (value * _multiplier);
}

void GameInformations::decreaseLife() {
    if (_lives > 0)
        _lives--;
}

void GameInformations::resetMultiplier() {
    _multiplier = 1;
}

void GameInformations::increaseMultiplier() {
    _multiplier++;
}
