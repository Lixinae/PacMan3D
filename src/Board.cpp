#include <Board.h>

#include <BoardPosition.h>
#include <BoardSquare.h>
#include <GameRepresentation.h>
#include <map>
#include <vector>

using namespace std;

Board::Board() : _squares() {
	
}

vector<BoardPosition> Board::getPositions() const {
	vector<BoardPosition> positions;
	for(map<BoardPosition,BoardSquare *>::const_iterator it = _squares.begin(); it != _squares.end(); ++it) {
		positions.push_back(it->first);
	}
	return positions;
}

const BoardSquare & Board::getSquare(const BoardPosition & position) const {
	//TODO Option Square <=> Square *
	return *(_squares.at(position));
}

const BoardSquare & Board::operator[](const BoardPosition & position) const {
	return getSquare(position);
}
