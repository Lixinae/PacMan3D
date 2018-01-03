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

	~TimeFloor();

	vector<GameRepresentation::Model> getModels() const;

	bool isPacmanWalkable(const BoardSquare::PacmanContext &context) const;

	void receivePacman(BoardSquare::PacmanContext &context);

	bool isGhostWalkable(const BoardSquare::GhostContext &context) const;

	void receiveGhost(BoardSquare::GhostContext &context);

	bool isDone() const;
	
	void iterate();

	BoardSquare *clone() const;

	json toJSON() const;

	TimeFloor &operator=(const TimeFloor &floor);

private:

	Bonus *_bonus;
	bool _bonusIsPresent;
	int _min_iter;
	int _max_iter;
	int _iter;

};

#endif
