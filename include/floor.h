#ifndef __FLOOR_H__
#define __FLOOR_H__

#include "boardSquare.h"
#include "pacman.h"
#include "bonus.h"
#include "boardRepresentation.h"

class Floor : public BoardSquare {

public:

	Floor();
	Floor(const Floor & floor);
	
	~Floor();
	
	BoardRepresentation::Model getModel() const; //TODO should be option model (empty case haven't model)
	
	bool isWalkable() const;
	
	void receive(Pacman pacman);
	
	Floor & operator=(const Floor & floor);
	
private:

	Bonus * _bonus; // bonus optional

};

#endif
