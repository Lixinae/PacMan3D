#ifndef __WALL_H__
#define __WALL_H__

#include <BoardSquare.h>
#include <Pacman.h>
#include <GameRepresentation.h>

class Wall : public BoardSquare {

public:

	Wall();

	vector<GameRepresentation::Model> getModels() const;

	bool isPacmanWalkable(const BoardSquare::PacmanContext &context) const;

	void receivePacman(BoardSquare::PacmanContext &context);

	bool isGhostWalkable(const BoardSquare::GhostContext &context) const;

	void receiveGhost(BoardSquare::GhostContext &context);

	BoardSquare *clone();

};

#endif
