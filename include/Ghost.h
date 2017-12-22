#ifndef __GHOST_H__
#define __GHOST_H__

#include <BoardPosition.h>
#include <GameRepresentation.h>
#include <Utils.h>

class Ghost {

public:

	static Ghost * fromJSON(const json & jsonGhost);

	Ghost(const BoardPosition & position, Utils::Orientation orientation);
	
	Utils::Orientation getOrientation() const;
	void setOrientation(Utils::Orientation orientation);
	
	BoardPosition getPosition() const;
	void setPosition(const BoardPosition & position);

	void iterate();

	virtual Utils::Orientation getNextOrientation() const = 0;
	
	virtual GameRepresentation::Model getModel() const = 0;

	virtual Ghost * clone() const = 0;

private:

	BoardPosition _position;
	Utils::Orientation _orientation;
	int _count;

};

#endif
