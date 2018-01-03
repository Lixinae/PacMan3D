#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <BoardSquare.h>
#include <Pacman.h>
#include <Bonus.h>
#include <GameRepresentation.h>

class Floor : public BoardSquare {

public:

	Floor();

	explicit Floor(const Bonus *bonus);

	Floor(const Floor &other);

	~Floor() override;

	vector<GameRepresentation::Model> getModels() const override;

	bool isPacmanWalkable(const BoardSquare::PacmanContext &context) const override;

	void receivePacman(BoardSquare::PacmanContext &context) override;

	bool isGhostWalkable(const BoardSquare::GhostContext &context) const override;

	void receiveGhost(BoardSquare::GhostContext &context) override;

	bool isDone() const override;

	void iterate() override;

	BoardSquare *clone() const override;

	json toJSON() const override;

	Floor &operator=(const Floor &floor);

private:

	Bonus *_bonus; // bonus optional

};

#endif
