#ifndef __FLOOR_H__
#define __FLOOR_H__

#include "boardSquare.h"
#include "pacman.h"
#include "bonus.h"

class Floor : public BoardSquare {

public:

	Floor();
	Floor(const Floor & floor);
	
	~Floor();
	
	bool isWalkable() const;
	
	void receive(Pacman pacman);
	
	Floor & operator=(const Floor & floor);
	
private:

	Bonus * _bonus; // bonus optional

};

#endif
