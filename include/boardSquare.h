#ifndef __BOARD_SQUARE_H__
#define __BOARD_SQUARE_H__

#include "pacman.h"
#include "boardRepresentation.h"

class BoardSquare {

public:
	
	virtual BoardRepresentation::Model getModel() const = 0;
	
	virtual bool isWalkable() const = 0;
	
	virtual void receive(Pacman pacman) = 0;
	
	virtual ~BoardSquare() {
		
	};

};

#endif
