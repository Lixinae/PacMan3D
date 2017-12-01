#include <Board.h>

#include <BoardPosition.h>
#include <BoardSquare.h>
#include <GameRepresentation.h>
#include <map>
#include <vector>

using namespace std;

Board::Board() : _squares() {
	
}
	
const BoardSquare & Board::getSquare(const BoardPosition & position) const {
	//TODO Option Square <=> Square *
	return *(_squares.at(position));
}

const BoardSquare & Board::operator[](const BoardPosition & position) const {
	return getSquare(position);
}
