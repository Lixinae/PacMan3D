#ifndef __BOARD_H__
#define __BOARD_H__

#include "boardPosition.h"
#include "boardSquare.h"

class Board {

public:

	Board(); // TODO should be private, the factory from file must be public

	BoardSquare * getSquare(const BoardPosition & position) const; // TODO return may be pointer or const reference
	
private:
 
	int width;
	int height;
	// TODO a map boardPosition -> boardSquare

};

#endif
