#ifndef __BOARD_SQUARE_H__
#define __BOARD_SQUARE_H__

#include <Pacman.h>
#include <GameRepresentation.h>
#include <vector>
#include <json/json.hpp>

using json = nlohmann::json;

class BoardSquare {

public:

	struct Context {
		
		Pacman & pacman;
		
		Context(Pacman & pacman);
		
	};
	
	static BoardSquare * fromJSON(const json & jsonSquare);
	
	virtual vector<GameRepresentation::Model> getModels() const = 0;
	
	virtual bool isWalkable() const = 0;
	
	virtual void receive(Context & context) = 0;
	
	virtual BoardSquare * clone() = 0;
	
	virtual ~BoardSquare() {
		
	};

};

#endif
