#ifndef __GAME_H__
#define __GAME_H__

#include <Board.h>
#include <Pacman.h>
#include <PointOfView.h>
#include <GameRepresentation.h>
#include <json/json.hpp>
#include <string>

using json = nlohmann::json;

using namespace std;

class Game {

public:
	
	static Game fromJSON(const json & jsonGame);
	static Game fromJSONFile(const string & filePath);
	
	PointOfView * getPointOfView();
	
	void orientPacman(Utils::Orientation orientation);
	
	GameRepresentation getRepresentation() const;
	
	void iterate();
	
private:
 
	Board _board;
	Pacman _pacman;
	PointOfView _pointOfView;
	
	GameRepresentation _representation;
	
	Game(Board board, Pacman pacman);

};

#endif
