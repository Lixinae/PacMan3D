#ifndef __BOARD_SQUARE_H__
#define __BOARD_SQUARE_H__

#include <Pacman.h>
#include <GameRepresentation.h>
#include <json/json.hpp>

using json = nlohmann::json;

class BoardSquare {

public:
	
	static BoardSquare * fromJSON(const json & jsonSquare);
	
	virtual GameRepresentation::Model getModel() const = 0;
	
	virtual bool isWalkable() const = 0;
	
	virtual void receive(Pacman pacman) = 0;
	
	virtual ~BoardSquare() {
		
	};

};

#endif
