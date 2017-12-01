#ifndef __BOARD_H__
#define __BOARD_H__

#include <BoardPosition.h>
#include <BoardSquare.h>
#include <GameRepresentation.h>
#include <map>
#include <vector>

using namespace std;

class Board {

public:

	Board(); // TODO should be private, the factory from file must be public

	map<GameRepresentation::Model, vector<BoardPosition>> * getModels() const; //TODO remove : use class boardrepr

	const BoardSquare & getSquare(const BoardPosition & position) const;
	
	const BoardSquare & operator[](const BoardPosition & position) const;
	
private:
 
	map<BoardPosition, BoardSquare *> _squares;

};

#endif