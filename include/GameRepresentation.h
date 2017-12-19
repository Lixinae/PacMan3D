#ifndef __BOARD_REPRESENTATION_H__
#define __BOARD_REPRESENTATION_H__

#include <BoardPosition.h>
#include <map>
#include <vector>

using namespace std;

class GameRepresentation {

public:

	enum class Model {
		
		PACMAN,
		WALL,
		FLOOR,
		TUNNEL,
		PAC_GOMME
		//TODO SUPER_PAC_GOMME, GHOST_SPEEDY, FRUIT_CHERRY, ...
		
		
		
	};
	
    static vector<Model> MODELS;

	static Model modelFromString(const string & strModel);

	GameRepresentation(); 
	
	const vector<BoardPosition> & getPositions(Model model) const;

	void add(Model model, const BoardPosition & position);
	
	void remove(Model model, const BoardPosition & position);
	
	const vector<BoardPosition> & operator[](Model model) const;
	
private:
 
	map<Model, vector<BoardPosition>> _modelsPositions;

    static vector<Model> buildVector();
};

#endif
