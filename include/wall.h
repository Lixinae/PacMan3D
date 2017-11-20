#ifndef __WALL_H__
#define __WALL_H__

#include "boardSquare.h"
#include "pacman.h"

class Wall : public BoardSquare {

public:

	Wall();
	
	bool isWalkable() const;
	
	void receive(Pacman pacman);
	
};

#endif
