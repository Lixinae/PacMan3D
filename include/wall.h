#ifndef __WALL_H__
#define __WALL_H__

#include "boardSquare.h"
#include "pacman.h"
#include "boardRepresentation.h"

class Wall : public BoardSquare {

public:

	Wall();
	
	BoardRepresentation::Model getModel() const; //TODO should be option model (empty case haven't model)
	
	bool isWalkable() const;
	
	void receive(Pacman pacman);
	
};

#endif
