#ifndef __BOARD_H__
#define __BOARD_H__

#include "boardPosition.h"
#include "boardSquare.h"
#include <vector>

using namespace std;

class Board {

public:

	Board(); // TODO should be private, the factory from file must be public

	const BoardSquare & getSquare(const BoardPosition & position) const;
	
	const BoardSquare & operator[](const BoardPosition & position) const;
	
private:
 
	int width;
	int height;
	BoardSquare *** squares; // TODO maybe change for a map<position *, square *>

};

#endif
