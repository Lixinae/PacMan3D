#include <Board.h>

#include <BoardPosition.h>
#include <BoardSquare.h>
#include <GameRepresentation.h>
#include <map>
#include <vector>

using namespace std;

Board::Board() : _squares() {
	
}
	
map<GameRepresentation::Model, vector<BoardPosition>> * Board::getModels() const {
	// TODO remove
	map<GameRepresentation::Model, vector<BoardPosition>> * modelsMap = new map<GameRepresentation::Model, vector<BoardPosition>>();
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
	return *(_squares.at(position));
}

const BoardSquare & Board::operator[](const BoardPosition & position) const {
	return getSquare(position);
}
