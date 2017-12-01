#include "board.h"

#include "boardPosition.h"
#include "boardSquare.h"
#include "boardRepresentation.h"
#include <map>
#include <vector>

using namespace std;

Board::Board() : _width(50), _height(50), _squares(nullptr), squares() { // TODO
	
}
	
map<BoardRepresentation::Model, vector<BoardPosition>> * Board::getModels() const {
	// TODO remove
	map<BoardRepresentation::Model, vector<BoardPosition>> * modelsMap = new map<BoardRepresentation::Model, vector<BoardPosition>>();
	/*for (int i = 0; i < _width; i++) {
		for (int j = 0; j < _height; j++) {
			BoardRepresentation::Model model = _squares[i][j]->getModel();
			(*modelsMap)[model].push_back(BoardPosition(i,j));
		}
	}*/
	return modelsMap;
}
	
const BoardSquare & Board::getSquare(const BoardPosition & position) const {
	//TODO Option Square <=> Square *
	return *(squares.at(position));
}

const BoardSquare & Board::operator[](const BoardPosition & position) const {
	return getSquare(position);
}
