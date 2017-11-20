#include "board.h"

#include "boardPosition.h"
#include "boardSquare.h"
#include "floor.h" // TODO Delete

Board::Board() : width(0), height(0) { // TODO

}
	
BoardSquare * Board::getSquare(const BoardPosition & /*position*/) const {
	// TODO impl
	return new Floor(); 
}
