#include <Game.h>

#include <fstream>

//TODO RM
#include <GhostBlinky.h>
#include <GhostPinky.h>
#include <GhostInky.h>
#include <GhostClyde.h>
//

using json = nlohmann::json;

using namespace std;

Game::Game(const Board & board, const Pacman & pacman, const vector<Ghost *> & ghosts) :
        _board(board),
        _pacman(pacman),
        _ghosts(ghosts),
        _pointOfView(),
        _representation()
{
    _representation.add(_pacman.getModel(), _pacman.getPosition());
    for (const Ghost * ghost : _ghosts) {
		_representation.add(ghost->getModel(), ghost->getPosition());
	}
    for (const BoardPosition & position : _board.getPositions()) {
        for (const GameRepresentation::Model & model : _board[position]->getModels()) {
            _representation.add(model, position);
        }
    }
}

Game Game::fromJSON(const json &jsonGame) {
    Board board = Board::fromJSON(jsonGame["board"]);
    Pacman pacman = Pacman::fromJSON(jsonGame["pacman"]);
    // TODO ghost from JSON
    Ghost * g1 = new GhostBlinky(BoardPosition(0,6),Utils::Orientation::SOUTH);
    Ghost * g2 = new GhostPinky(BoardPosition(0,-6),Utils::Orientation::NORTH);
    Ghost * g3 = new GhostInky(BoardPosition(-6,0),Utils::Orientation::EAST);
    Ghost * g4 = new GhostClyde(BoardPosition(6,0),Utils::Orientation::WEST);
    vector<Ghost *> ghosts = {g1, g2, g3, g4};
    // ///////      ///
    return Game(board, pacman, ghosts);
}

Game Game::fromJSONFile(const string &filePath) {
    json jsonGame;
    ifstream gameFile(filePath);
    gameFile >> jsonGame;
    gameFile.close();
    return fromJSON(jsonGame);
}

void Game::orientPacman(Utils::Orientation orientation) {
    BoardPosition position = _pacman.getPosition().translate(orientation);
    BoardSquare *square = _board[position];
    BoardSquare::PacmanContext context(_pacman);
    if (square != nullptr && square->isPacmanWalkable(context)) {
        _pacman.setOrientation(orientation);
    }
}

PointOfView *Game::getPointOfView() {
    return &_pointOfView;
}

const GameRepresentation &Game::getRepresentation() const {
    return _representation;
}

void Game::setSquare(const BoardPosition &position) {
    for (const GameRepresentation::Model & model : _board[position]->getModels()) {
        _representation.add(model, position);
    }
}

void Game::setPacman() {
    _representation.add(_pacman.getModel(), _pacman.getPosition());
}

void Game::setGhost(const Ghost * ghost) {
	 _representation.add(ghost->getModel(), ghost->getPosition());
}

void Game::cleanSquare(const BoardPosition &position) {
    for (const GameRepresentation::Model & model : _board[position]->getModels()) {
        _representation.remove(model, position);
    }
}

void Game::cleanPacman() {
    _representation.remove(_pacman.getModel(), _pacman.getPosition());
}

void Game::cleanGhost(const Ghost * ghost) {
	_representation.remove(ghost->getModel(), ghost->getPosition());
}

void Game::iteratePacman() {
	BoardPosition nextPosition = _pacman.getPosition().translate(_pacman.getOrientation());
    BoardSquare *nextSquare = _board[nextPosition];
    BoardSquare::PacmanContext context(_pacman);
    if (nextSquare != nullptr && nextSquare->isPacmanWalkable(context)) {
        // Clean models
        cleanSquare(nextPosition);
        cleanPacman();
        // Update
        _pacman.setPosition(nextPosition);
        nextSquare->receivePacman(context);
        // Reset models
        setSquare(nextPosition);
        setPacman();
    }
    _pacman.iterate();
}

void Game::iterateGhost(Ghost * ghost) {
	BoardPosition nextPosition = ghost->getPosition().translate(ghost->getOrientation());
    BoardSquare *nextSquare = _board[nextPosition];
    BoardSquare::GhostContext context;
	if (nextSquare != nullptr && nextSquare->isGhostWalkable(context)) {
		cleanSquare(nextPosition);
		cleanGhost(ghost);
        ghost->setPosition(nextPosition);
        nextSquare->receiveGhost(context);
        setSquare(nextPosition);
		setGhost(ghost);
	}
	ghost->iterate();
}

void Game::iterate() {
    iteratePacman();
    for (Ghost * ghost : _ghosts) {
		iterateGhost(ghost);
	}
}
