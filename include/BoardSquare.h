#ifndef __BOARD_SQUARE_H__
#define __BOARD_SQUARE_H__

#include <Pacman.h>
#include <GameRepresentation.h>

class BoardSquare {

public:
	
	virtual GameRepresentation::Model getModel() const = 0;
	
	virtual bool isWalkable() const = 0;
	
	virtual void receive(Pacman pacman) = 0;
	
	virtual ~BoardSquare() {
		
	};

};

#endif
