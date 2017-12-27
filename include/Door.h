#ifndef __DOOR_H__
#define __DOOR_H__

#include <BoardSquare.h>
#include <GameRepresentation.h>

class Door : public BoardSquare {

public:

	Door();

	vector<GameRepresentation::Model> getModels() const;

	bool isPacmanWalkable(const BoardSquare::PacmanContext &context) const;

	void receivePacman(BoardSquare::PacmanContext &context);

	bool isGhostWalkable(const BoardSquare::GhostContext &context) const;

	void receiveGhost(BoardSquare::GhostContext &context);

	BoardSquare *clone() const;
	
	json toJSON() const;

};

#endif
