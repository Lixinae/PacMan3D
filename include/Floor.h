#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <BoardSquare.h>
#include <Pacman.h>
#include <Bonus.h>
#include <GameRepresentation.h>

class Floor : public BoardSquare {

public:

	Floor();
	Floor(const Bonus * bonus);
	Floor(const Floor & other);
	
	~Floor();
	
	vector<GameRepresentation::Model> getModels() const;
	
	bool isPacmanWalkable(const BoardSquare::PacmanContext & context) const;
	
	void receivePacman(BoardSquare::PacmanContext & context);
	
	BoardSquare * clone();
	
	Floor & operator=(const Floor & floor);
	
private:

	Bonus * _bonus; // bonus optional

};

#endif
