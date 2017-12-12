#include <Game.h>

#include <fstream>

using json = nlohmann::json;

using namespace std;

Game::Game(Board board, Pacman pacman) : _board(board), _pacman(pacman), _pointOfView(), _representation() {
	_representation.add(_pacman.getModel(), _pacman.getPosition());
    for (auto &position : _board.getPositions()) {
		_representation.add(_board[position].getModel(), position);
    }
}

Game Game::fromJSON(const json &jsonGame) {
    Board board = Board::fromJSON(jsonGame["board"]);
    Pacman pacman = Pacman::fromJSON(jsonGame["pacman"]);
    return Game(board, pacman);
}

Game Game::fromJSONFile(const string &filePath) {
    json jsonGame;
    ifstream gameFile(filePath);
    gameFile >> jsonGame;
    gameFile.close();
    return fromJSON(jsonGame);
}

void Game::orientPacman(Utils::Orientation orientation) {
	_pacman.setOrientation(orientation);
}

PointOfView & Game::getPointOfView() {
    return _pointOfView;
}

GameRepresentation Game::getRepresentation() const {
    return _representation;
}

void Game::iterate() {
	BoardPosition nextPosition = _pacman.getNextPosition();
    if (_board[nextPosition].isWalkable()) {
		GameRepresentation::Model pacmanModel = _pacman.getModel();
		_representation.remove(pacmanModel, _pacman.getPosition());
		_pacman.setNextPosition(); // TODO may be in case.receive
		_representation.add(pacmanModel, nextPosition);
	}
}
