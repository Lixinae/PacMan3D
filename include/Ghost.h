#ifndef __GHOST_H__
#define __GHOST_H__

#include <BoardPosition.h>
#include <GameRepresentation.h>
#include <Utils.h>

using json = nlohmann::json;

class Ghost {

public:

	struct MovingContext {

		vector<Utils::Orientation> &availableOrientation;
		
		MovingContext(vector<Utils::Orientation> &availableOrientation);

	};

	static int MAX_ITERATION;

	static Ghost *fromJSON(const json &jsonGhost);

	Ghost(const BoardPosition &position, Utils::Orientation orientation);

	Utils::Orientation getOrientation() const;

	void setOrientation(Utils::Orientation orientation);
	
	bool orientTo(Utils::Orientation orientation);

	BoardPosition getPosition() const;

	void setPosition(const BoardPosition &position);

	bool goTo(const BoardPosition &position);
	
	bool isWeak() const;

	void setWeak(int time);
	
	bool canCrossDoor();
	
	void crossDoor();

	float getShift() const;

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
	int _iterOrientation;
	int _weakCounter;
	bool _crossDoor;

};

#endif
