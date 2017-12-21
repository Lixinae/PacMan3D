#ifndef __PACMAN_H__
#define __PACMAN_H__

#include <BoardPosition.h>
#include <GameRepresentation.h>
#include <json/json.hpp>
#include <Utils.h>

using json = nlohmann::json;

class Pacman {
	
public:

	static Pacman fromJSON(const json & jsonPacman);
	
	Utils::Orientation getOrientation() const;
	void setOrientation(Utils::Orientation orientation);
	
	BoardPosition getPosition() const;
	void setPosition(const BoardPosition & position);

	void iterate();
	
	GameRepresentation::Model getModel() const;
		
private:
	
	BoardPosition _position;
	Utils::Orientation _orientation;
	
	Pacman(const BoardPosition & position, Utils::Orientation orientation);

};

#endif
