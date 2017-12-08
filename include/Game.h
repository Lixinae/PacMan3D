#ifndef __GAME_H__
#define __GAME_H__

#include <Board.h>
#include <Pacman.h>
#include <GameRepresentation.h>
#include <json/json.hpp>

using json = nlohmann::json;

class Game {

public:
	
	static Game fromJSON(json jsonGame);
	
	Pacman & getPacman(); //TODO do not return the pacman : apply the transformation locally in game
	
	GameRepresentation getRepresentation() const; // TODO repr may be a field
	
	void iterate(); // TODO maybe remove
	
private:
 
	Board _board;
	Pacman _pacman;
	
	Game(Board board, Pacman pacman);

};

#endif
