#ifndef __GAME_H__
#define __GAME_H__

#include <Board.h>
#include <Pacman.h>
#include <GameRepresentation.h>

using namespace std;

class Game {

public:

	Game(); // TODO private, public factory from json
	
	GameRepresentation getRepresentation() const; // TODO repr may be a field
	
	void iterate();
	
private:
 
	Board _board;
	Pacman _pacman;

};

#endif
