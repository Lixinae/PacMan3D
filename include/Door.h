#ifndef __DOOR_H__
#define __DOOR_H__

#include <BoardSquare.h>
#include <GameRepresentation.h>

class Door : public BoardSquare {

public:

	Door();

	vector<GameRepresentation::Model> getModels() const override;

	bool isPacmanWalkable(const BoardSquare::PacmanContext &context) const override;

	void receivePacman(BoardSquare::PacmanContext &context) override;

	bool isGhostWalkable(const BoardSquare::GhostContext &context) const override;

	void receiveGhost(BoardSquare::GhostContext &context) override;

	bool isDone() const override;

	void iterate() override;

	BoardSquare *clone() const override;

	json toJSON() const override;

};

#endif
