#include <Game.h>

#include <fstream>

using json = nlohmann::json;

using namespace std;

Game::Game(Board board, Pacman pacman) : _board(board), _pacman(pacman), _pointOfView(), _representation() {
	_representation.add(_pacman.getModel(), _pacman.getPosition());
    for (const BoardPosition & position : _board.getPositions()) {
		for (const GameRepresentation::Model & model : _board[position].getModels()) {
			_representation.add(model, position);
		}
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
	BoardPosition nextPosition = _pacman.getPosition().translate(orientation);
	if (_board[nextPosition].isWalkable()) {
		_pacman.setOrientation(orientation);
	}
}

PointOfView & Game::getPointOfView() {
    return _pointOfView;
}

GameRepresentation Game::getRepresentation() const {
    return _representation;
}

void Game::iterate() {
	BoardPosition nextPosition = _pacman.getPosition().translate(_pacman.getOrientation());
	BoardSquare & square = _board[nextPosition];
    if (square.isWalkable()) {
		// Clean model
		GameRepresentation::Model pacmanModel = _pacman.getModel();
		for (const GameRepresentation::Model & model : square.getModels()) {
			_representation.remove(model, nextPosition);
		}
		_representation.remove(pacmanModel, _pacman.getPosition());
		// Update
		_pacman.setPosition(nextPosition);
		square.receive(_pacman);
		// Reset model
		for (const GameRepresentation::Model & model : square.getModels()) {
			_representation.add(model, nextPosition);
		}
		_representation.add(pacmanModel, nextPosition);
	}
	_pacman.iterate();
}
