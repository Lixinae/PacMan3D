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
		GHOST_BLINKY,
		GHOST_PINKY,
		GHOST_INKY,
		GHOST_CLYDE,
		GHOST_WEAK,
		WALL,
		FLOOR,
		TUNNEL,
		PAC_GOMME,
		SUPER_PAC_GOMME	
		
	};
	
	struct Model {
		
		ModelType modelType;
		Utils::Orientation orientation;
		
		Model(ModelType modelType, Utils::Orientation orientation);
		Model(ModelType modelType);
		
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

	void add(Model model, const BoardPosition & position);
	
	void remove(Model model, const BoardPosition & position);
	
	const vector<ModelInformations> & operator[](ModelType modelType) const;
	
private:
 
	map<ModelType, vector<ModelInformations>> _modelsPositions;

    static vector<ModelType> buildVector();
};

#endif
