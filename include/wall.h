#ifndef __WALL_H__
#define __WALL_H__

#include "boardSquare.h"
#include "pacman.h"
#include "renderer.h"

class Wall : public BoardSquare {

public:

	Wall();
	
	Renderer::Model getModel() const; //TODO should be option model (empty case haven't model)
	
	bool isWalkable() const;
	
	void receive(Pacman pacman);
	
};

#endif
