#include <Game.h>

#include <fstream>
#include <Utils.h>

using json = nlohmann::json;

using namespace std;

Game::Game(const Board & board, const Pacman & pacman, const vector<Ghost *> & ghosts) :
        _board(board),
        _pacman(pacman),
        _ghosts(),
        _pointOfView(),
        _representation()
{
    _representation.add(_pacman.getModel(), _pacman.getPosition());
    for (const Ghost * ghost : ghosts) {
		_ghosts.push_back(ghost->clone());
		_representation.add(ghost->getModel(), ghost->getPosition());
	}
    for (const BoardPosition & position : _board.getPositions()) {
        for (const GameRepresentation::Model & model : _board[position]->getModels()) {
            _representation.add(model, position);
        }
    }
}

Game::~Game() {
	Utils::cleanVector(_ghosts);
}

Game Game::fromJSON(const json &jsonGame) {
    Board board = Board::fromJSON(jsonGame["board"]);
    Pacman pacman = Pacman::fromJSON(jsonGame["pacman"]);
    vector<Ghost *> ghosts;
    for (const auto &it : jsonGame["ghosts"]) {
        ghosts.push_back(Ghost::fromJSON(it));
	}
    Game game(board, pacman, ghosts);
    Utils::cleanVector(ghosts);
    return game;
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
