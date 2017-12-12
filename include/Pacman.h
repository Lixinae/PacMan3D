#ifndef __PACMAN_H__
#define __PACMAN_H__

#include <BoardPosition.h>
#include <json/json.hpp>

using json = nlohmann::json;

class Pacman {
	
public:

	enum class Orientation {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};

	static Pacman fromJSON(const json & jsonPacman);
	
	void setOrientation(Orientation orientation);
	
	BoardPosition getPosition() const;
	BoardPosition getNextPosition() const;
	void setNextPosition(const BoardPosition & position); // TODO maybe position not in argument
		
private:
	
	BoardPosition _position;
	Orientation _orientation;
	
	Pacman(const BoardPosition & position, Orientation orientation);
	
	static Orientation orientationFromString(string strOrientation);

};

#endif
