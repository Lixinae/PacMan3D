#ifndef __WALL_H__
#define __WALL_H__

#include <BoardSquare.h>
#include <Pacman.h>
#include <GameRepresentation.h>

class Wall : public BoardSquare {

public:

	Wall();
	
	GameRepresentation::Model getModel() const; //TODO should be option model (empty case haven't model)
	
	bool isWalkable() const;
	
	void receive(Pacman pacman);
	
};

#endif
