#ifndef __BOARD_REPRESENTATION_H__
#define __BOARD_REPRESENTATION_H__

#include <BoardPosition.h>
#include <map>
#include <vector>

using namespace std;

class GameRepresentation {

public:

	enum class ModelType {
		
		PACMAN,
		WALL,
		FLOOR,
		TUNNEL,
		PAC_GOMME
		//TODO SUPER_PAC_GOMME, GHOST_SPEEDY, FRUIT_CHERRY, ...	
		
	};
	
    static vector<ModelType> MODELS;

	static ModelType modelFromString(const string & strModel);

	GameRepresentation(); 
	
	const vector<BoardPosition> & getPositions(ModelType modelType) const;

	void add(ModelType modelType, const BoardPosition & position);
	
	void remove(ModelType modelType, const BoardPosition & position);
	
	const vector<BoardPosition> & operator[](ModelType modelType) const;
	
private:
 
	map<ModelType, vector<BoardPosition>> _modelsPositions;

    static vector<ModelType> buildVector();
};

#endif
