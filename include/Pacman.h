#ifndef __PACMAN_H__
#define __PACMAN_H__

#include <BoardPosition.h>
#include <json/json.hpp>
#include <Utils.h>

using json = nlohmann::json;

class Pacman {
	
public:

	static Pacman fromJSON(const json & jsonPacman);
	
	void setOrientation(Utils::Orientation orientation);
	
	BoardPosition getPosition() const;
	BoardPosition getNextPosition() const;
	void setNextPosition();
		
private:
	
	BoardPosition _position;
	Utils::Orientation _orientation;
	
	Pacman(const BoardPosition & position, Utils::Orientation orientation);

};

#endif
