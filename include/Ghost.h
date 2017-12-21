#ifndef __GHOST_H__
#define __GHOST_H__

#include <BoardPosition.h>
#include <GameRepresentation.h>
#include <Utils.h>

class Ghost {

public:

	Ghost(const BoardPosition & position, Utils::Orientation orientation);
	
	Utils::Orientation getOrientation();
	void setOrientation(Utils::Orientation orientation); // TODO rm
	
	BoardPosition getPosition() const;
	void setPosition(const BoardPosition & position);

	void iterate();

	//TODO behavior : setNextOrientation = 0
	
	virtual GameRepresentation::Model getModel() const = 0;

private:

	BoardPosition _position;
	Utils::Orientation _orientation;

};

#endif
