#include <Game.h>

#include <fstream>

using json = nlohmann::json;

using namespace std;

Game::Game(const Board &board, const Pacman &pacman) :
        _board(board),
        _pacman(pacman),
        _pointOfView(),
        _representation(){
    _representation.add(_pacman.getModel(), _pacman.getPosition());
    for (const BoardPosition &position : _board.getPositions()) {
        for (const GameRepresentation::ModelType &modelType : _board[position]->getModels()) {
            _representation.add(modelType, position);
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
    for (const GameRepresentation::ModelType &modelType : _board[position]->getModels()) {
        _representation.add(modelType, position);
    }
}

void Game::setPacman() {
    _representation.add(_pacman.getModel(), _pacman.getPosition());
}

void Game::cleanSquare(const BoardPosition &position) {
    for (const GameRepresentation::ModelType &modelType : _board[position]->getModels()) {
        _representation.remove(modelType, position);
    }
}

void Game::cleanPacman() {
    _representation.remove(_pacman.getModel(), _pacman.getPosition());
}

void Game::iterate() {
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
