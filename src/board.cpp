#include "board.h"

#include "boardPosition.h"
#include "boardSquare.h"
#include "floor.h" // TODO Delete
#include <map>
#include <vector>

using namespace std;

Board::Board() : _width(50), _height(50), _squares(nullptr) { // TODO
	_squares = new BoardSquare ** [_width];
	for (int i = 0; i < _width; i++) {
		_squares[i] = new BoardSquare * [_height];
		for (int j = 0; j < _height; j++) {
			_squares[i][j] = new Floor();
		}
	}
	
}
	
map<Renderer::Model, vector<BoardPosition>> * Board::getModels() const {
	// TODO change impl
	map<Renderer::Model, vector<BoardPosition>> * modelsMap = new map<Renderer::Model, vector<BoardPosition>>();
	for (int i = 0; i < _width; i++) {
		for (int j = 0; j < _height; j++) {
			Renderer::Model model = _squares[i][j]->getModel();
			(*modelsMap)[model].push_back(BoardPosition(i,j));
		}
	}
	return modelsMap;
}
	
const BoardSquare & Board::getSquare(const BoardPosition & position) const {
	// TODO check index 0 <= x < width
	// TODO check index 0 <= y < heigh
	return *(_squares[position.getX()][position.getY()]); 
}

const BoardSquare & Board::operator[](const BoardPosition & position) const {
	return getSquare(position);
}
