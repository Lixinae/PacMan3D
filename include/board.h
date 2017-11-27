#ifndef __BOARD_H__
#define __BOARD_H__

#include "boardPosition.h"
#include "boardSquare.h"
#include "boardRepresentation.h"
#include <map>
#include <vector>

using namespace std;

class Board {

public:

	Board(); // TODO should be private, the factory from file must be public

	map<BoardRepresentation::Model, vector<BoardPosition>> * getModels() const; //TODO remove : use class boardrepr

	const BoardSquare & getSquare(const BoardPosition & position) const;
	
	const BoardSquare & operator[](const BoardPosition & position) const;
	
private:
 
	int _width;
	int _height;
	BoardSquare *** _squares; // TODO maybe change for a map<position *, square *>

};

#endif
