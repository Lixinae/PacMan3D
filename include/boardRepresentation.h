#ifndef __BOARD_REPRESENTATION_H__
#define __BOARD_REPRESENTATION_H__

#include "boardPosition.h"
#include "renderer.h"
#include <map>
#include <vector>

using namespace std;

class BoardRepresentation {

public:

	BoardRepresentation(); 
	
	vector<BoardPosition> getPositions(Renderer::Model model) const;

	void add(Renderer::Model model, const BoardPosition & position);
	
	void remove(Renderer::Model model, const BoardPosition & position);
	
	vector<BoardPosition> operator[](Renderer::Model model) const;
	
private:
 
	// TODO maybe map<Renderer::Model, vector<BoardPosition>>

};

#endif
