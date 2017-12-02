#ifndef __PACMAN_H__
#define __PACMAN_H__

#include <BoardPosition.h>

class Pacman {
	
public:

	enum class Orientation {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};

	Pacman(const BoardPosition & position, Orientation orientation);
	
	void setOrientation(Orientation orientation);
	
	BoardPosition getPosition() const;
	BoardPosition getNextPosition() const;
	void setNextPosition(const BoardPosition & position); // TODO maybe position not in argument
		
private:
	
	BoardPosition _position;
	Orientation _orientation;

};

#endif
