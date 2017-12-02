#include <Game.h>

#include <Board.h>
#include <Pacman.h>
#include <GameRepresentation.h>
#include <BoardPosition.h>

Game::Game() : _board(), _pacman(BoardPosition(50,50), Pacman::Orientation::WEST) { //TODO

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
