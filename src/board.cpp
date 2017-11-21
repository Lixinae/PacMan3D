#include "board.h"

#include "boardPosition.h"
#include "boardSquare.h"
#include "floor.h" // TODO Delete

Board::Board() : width(50), height(50), squares(nullptr) { // TODO
	squares = new BoardSquare ** [width];
	for (int i = 0; i < width; i++) {
		squares[i] = new BoardSquare * [height];
		for (int j = 0; j < height; j++) {
			squares[i][j] = new Floor();
		}
	}
	
}
	
const BoardSquare & Board::getSquare(const BoardPosition & position) const {
	// TODO check index 0 <= x < width
	// TODO check index 0 <= y < heigh
	return *(squares[position.getX()][position.getY()]); 
}

const BoardSquare & Board::operator[](const BoardPosition & position) const {
	return getSquare(position);
}
