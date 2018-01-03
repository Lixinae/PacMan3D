#ifndef __TIME_FLOOR_H__
#define __TIME_FLOOR_H__

#include <BoardSquare.h>
#include <Pacman.h>
#include <Bonus.h>
#include <GameRepresentation.h>

class TimeFloor : public BoardSquare {

public:

	TimeFloor(const Bonus *bonus, bool bonusIsPresent, int min_iter, int max_iter, int iter);

	TimeFloor(const TimeFloor &other);

	~TimeFloor() override;

	vector<GameRepresentation::Model> getModels() const override;

	bool isPacmanWalkable(const BoardSquare::PacmanContext &context) const override;

	void receivePacman(BoardSquare::PacmanContext &context) override;

	bool isGhostWalkable(const BoardSquare::GhostContext &context) const override;

	void receiveGhost(BoardSquare::GhostContext &context) override;

	bool isDone() const override;

	void iterate() override;

	BoardSquare *clone() const override;

	json toJSON() const override;

	TimeFloor &operator=(const TimeFloor &floor);

private:

	Bonus *_bonus;
	bool _bonusIsPresent;
	int _min_iter;
	int _max_iter;
	int _iter;

};

#endif
