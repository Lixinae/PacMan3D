#ifndef __BOARD_REPRESENTATION_H__
#define __BOARD_REPRESENTATION_H__

#include <BoardPosition.h>
#include <map>
#include <vector>
#include <Utils.h>

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
	
	struct ModelInformations {
		
		BoardPosition position;
		Utils::Orientation orientation;
		
		ModelInformations(const BoardPosition & position, Utils::Orientation orientation);
		
	};
	
    static vector<ModelType> MODELS;

	static ModelType modelFromString(const string & strModel);

	GameRepresentation(); 
	
	const vector<ModelInformations> & getPositions(ModelType modelType) const;

	void add(ModelType modelType, const BoardPosition & position);
	
	void remove(ModelType modelType, const BoardPosition & position);
	
	const vector<ModelInformations> & operator[](ModelType modelType) const;
	
private:
 
	map<ModelType, vector<ModelInformations>> _modelsPositions;

    static vector<ModelType> buildVector();
};

#endif
