#ifndef __GHOST_H__
#define __GHOST_H__

#include <BoardPosition.h>
#include <GameRepresentation.h>
#include <Pacman.h>
#include <Utils.h>

using json = nlohmann::json;

class Ghost {

public:

	struct MovingContext {

		Pacman &pacman;
		function<vector<Utils::Orientation>()> &availableOrientation;
		function<Utils::Orientation()> &orientationOnPacman;
		function<Utils::Orientation()> &orientationBlockPacman;
		function<Utils::Orientation()> &orientationAvoidPacman;
		
		MovingContext(
			Pacman &pacman,
			function<vector<Utils::Orientation>()> &availableOrientation,
			function<Utils::Orientation()> &orientationOnPacman,
			function<Utils::Orientation()> &orientationBlockPacman,
			function<Utils::Orientation()> &orientationAvoidPacman
		);

	};

	static int CASE_REDIRECTION_ITERATION;
	static int MAX_ITERATION;

	static Ghost *fromJSON(const json &jsonGhost);

	Ghost(const BoardPosition &position, Utils::Orientation orientation);

	Utils::Orientation getOrientation() const;

	void setOrientation(Utils::Orientation orientation);
	
	bool orientToTarget(const MovingContext & context);

	BoardPosition getPosition() const;

	void setPosition(const BoardPosition &position);

	vector<BoardPosition> getGraphicalPositions() const;

	bool goTo(const BoardPosition &position);
	
	bool isWeak() const;

	void setWeak(int time);
	
	bool canCrossDoor();
	
	void crossDoor();

	float getShift() const;

	void iterate();

	GameRepresentation::Model getModel() const;

	virtual Utils::Orientation getNextOrientation(const MovingContext & context) const = 0;

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
