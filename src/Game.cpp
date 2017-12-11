#include <Game.h>
#include <fstream>

using json = nlohmann::json;

using namespace std;

Game::Game(Board board, Pacman pacman) : _board(board), _pacman(pacman), _pointOfView() {

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

Pacman & Game::getPacman() {
    return _pacman;
}

PointOfView & Game::getPointOfView() {
    return _pointOfView;
}

GameRepresentation Game::getRepresentation() const {
    GameRepresentation representation; // TODO use field to avoid all computation
    representation.add(GameRepresentation::Model::PACMAN, _pacman.getPosition());
    for (auto &position : _board.getPositions()) {
        representation.add(_board[position].getModel(), position);
    }
    return representation;
}

void Game::iterate() {
    // TODO
    BoardPosition pacmanPosition = _pacman.getPosition();

}
