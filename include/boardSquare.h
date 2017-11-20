#ifndef __BOARD_SQUARE_H__
#define __BOARD_SQUARE_H__

#include "pacman.h"

class BoardSquare {

public:
	
	virtual bool isWalkable() const = 0;
	
	virtual void receive(Pacman pacman) = 0;
	
	virtual ~BoardSquare() {
		
	};

};

#endif
