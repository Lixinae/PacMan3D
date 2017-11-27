#ifndef __BOARD_REPRESENTATION_H__
#define __BOARD_REPRESENTATION_H__

#include "boardPosition.h"
#include <map>
#include <vector>

using namespace std;

class BoardRepresentation {

public:

	enum class Model {
		PACMAN,
		WALL,
		PAC_GOMME
		//TODO SUPER_PAC_GOMME, GHOST_SPEEDY, FRUIT_CHERRY, ...
	};

	BoardRepresentation(); 
	
	vector<BoardPosition> getPositions(Model model) const;

	void add(Model model, const BoardPosition & position);
	
	void remove(Model model, const BoardPosition & position);
	
	vector<BoardPosition> operator[](Model model) const;
	
private:
 
	// TODO maybe map<Renderer::Model, vector<BoardPosition>>

};

#endif
