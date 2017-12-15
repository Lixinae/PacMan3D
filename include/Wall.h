#ifndef __WALL_H__
#define __WALL_H__

#include <BoardSquare.h>
#include <Pacman.h>
#include <GameRepresentation.h>

class Wall : public BoardSquare {

public:

	Wall();
	
	vector<GameRepresentation::Model> getModels() const;
	
	bool isWalkable() const;
	
	void receive(Pacman & pacman);
	
};

#endif
