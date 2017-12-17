#include <Game.h>

#include <fstream>

using json = nlohmann::json;

using namespace std;

Game::Game(const Board & board, const Pacman & pacman) : _board(board), _pacman(pacman), _pointOfView(), _representation() {
	_representation.add(_pacman.getModel(), _pacman.getPosition());
    for (const BoardPosition & position : _board.getPositions()) {
		for (const GameRepresentation::Model & model : _board[position]->getModels()) {
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
	BoardSquare * square = _board[nextPosition];
	if (square != nullptr && square->isWalkable()) {
		_pacman.setOrientation(orientation);
	}
}

PointOfView * Game::getPointOfView() {
    return &_pointOfView;
}

GameRepresentation Game::getRepresentation() const {
    return _representation;
}

void Game::iterate() {
	BoardPosition nextPosition = _pacman.getPosition().translate(_pacman.getOrientation());
	BoardSquare * square = _board[nextPosition];
    if (square != nullptr && square->isWalkable()) {
		// Clean model
		for (const GameRepresentation::Model & model : square->getModels()) {
			_representation.remove(model, nextPosition);
		}
		_representation.remove(_pacman.getModel(), _pacman.getPosition());
		// Update
		_pacman.setPosition(nextPosition);
		BoardSquare::Context context(_pacman);
		square->receive(context);
		// Reset model
		/* TODO better : add new pacman pos */
		for (const GameRepresentation::Model & model : square->getModels()) {
			_representation.add(model, nextPosition);
		}
		/* *** */
		_representation.add(_pacman.getModel(), _pacman.getPosition());
	}
	_pacman.iterate();
}
