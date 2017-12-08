#include <Game.h>

#include <Board.h>
#include <Pacman.h>
#include <GameRepresentation.h>
#include <BoardPosition.h>
#include <json/json.hpp>

using json = nlohmann::json;

Game::Game(Board board, Pacman pacman) : _board(board), _pacman(pacman) {

}

Game Game::fromJSON(json jsonGame) {
	Board board = Board::fromJSON(jsonGame["board"]);
	Pacman pacman = Pacman::fromJSON(jsonGame["pacman"]);
	return Game(board, pacman);
}

Pacman & Game::getPacman() {
	return _pacman;
}

GameRepresentation Game::getRepresentation() const {
	GameRepresentation representation; // TODO use field to avoid all computation
	representation.add(GameRepresentation::Model::PACMAN, _pacman.getPosition());
	for (auto & position : _board.getPositions()) {  
		representation.add(_board[position].getModel(), position);
	}
	return representation;
}

void Game::iterate() {
	// TODO
	BoardPosition pacmanPosition = _pacman.getPosition();
	
}
