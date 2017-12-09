#ifndef __GAME_H__
#define __GAME_H__

#include <Board.h>
#include <Pacman.h>
#include <GameRepresentation.h>
#include <json/json.hpp>
#include <string>

using json = nlohmann::json;

using namespace std;

class Game {

public:
	
	static Game fromJSON(const json & jsonGame);
	static Game fromJSONFile(const string & filePath);
	
	Pacman & getPacman(); //TODO do not return the pacman : apply the transformation locally in game
	
	GameRepresentation getRepresentation() const; // TODO repr may be a field
	
	void iterate(); // TODO maybe remove
	
private:
 
	Board _board;
	Pacman _pacman;
	
	Game(Board board, Pacman pacman);

};

#endif
