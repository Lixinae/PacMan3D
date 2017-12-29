#ifndef __PACMAN_H__
#define __PACMAN_H__

#include <BoardPosition.h>
#include <GameRepresentation.h>
#include <json/json.hpp>
#include <Utils.h>

using json = nlohmann::json;

class Pacman {

public:

	static int MAX_ITERATION;

	static Pacman fromJSON(const json &jsonPacman);

	Utils::Orientation getOrientation() const;

	void setOrientation(Utils::Orientation orientation);
	
	bool orientTo(Utils::Orientation orientation);

	BoardPosition getPosition() const;

	void setPosition(const BoardPosition &position);

	void goTo(const BoardPosition &position);

	float getShift() const;
	
	bool move();
	
	void iterate();

	GameRepresentation::Model getModel() const;
	
	json toJSON() const;

private:

	BoardPosition _position;
	Utils::Orientation _orientation;
	BoardPosition _nextPosition;
	int _iterPosition;
	int _iterOrientation;

	Pacman(const BoardPosition &position, Utils::Orientation orientation);

};

#endif
