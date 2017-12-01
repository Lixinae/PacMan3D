#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <BoardSquare.h>
#include <Pacman.h>
#include <Bonus.h>
#include <GameRepresentation.h>

class Floor : public BoardSquare {

public:

	Floor();
	Floor(const Floor & floor);
	
	~Floor();
	
	GameRepresentation::Model getModel() const; //TODO should be option model (empty case haven't model)
	
	bool isWalkable() const;
	
	void receive(Pacman pacman);
	
	Floor & operator=(const Floor & floor);
	
private:

	Bonus * _bonus; // bonus optional

};

#endif
