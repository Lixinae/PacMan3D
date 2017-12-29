#ifndef __GHOST_H__
#define __GHOST_H__

#include <BoardPosition.h>
#include <GameRepresentation.h>
#include <Utils.h>

using json = nlohmann::json;

class Ghost {

public:

	static int MAX_ITERATION;

	static Ghost *fromJSON(const json &jsonGhost);

	Ghost(const BoardPosition &position, Utils::Orientation orientation);

	Utils::Orientation getOrientation() const;

	void setOrientation(Utils::Orientation orientation);

	BoardPosition getPosition() const;

	void setPosition(const BoardPosition &position);

	void goTo(const BoardPosition &position);
	
	bool isWeak() const;

	void setWeak(int time);
	
	bool canCrossDoor();
	
	void crossDoor();

	float getShift() const;
	
	void move();

	void iterate();

	GameRepresentation::Model getModel() const;

	virtual Utils::Orientation getNextOrientation() const = 0;

	virtual GameRepresentation::ModelType getModelType() const = 0;

	virtual Ghost *clone() const = 0;
	
	virtual json toJSON() const = 0;

private:

	BoardPosition _position;
	Utils::Orientation _orientation;
	BoardPosition _nextPosition;
	int _iterPosition;
	int _weakCounter;
	int _count;
	bool _crossDoor;

};

#endif
