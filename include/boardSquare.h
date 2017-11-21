#ifndef __BOARD_SQUARE_H__
#define __BOARD_SQUARE_H__

#include "pacman.h"
#include "renderer.h"

class BoardSquare {

public:
	
	virtual Renderer::Model getModel() const = 0;
	
	virtual bool isWalkable() const = 0;
	
	virtual void receive(Pacman pacman) = 0;
	
	virtual ~BoardSquare() {
		
	};

};

#endif
