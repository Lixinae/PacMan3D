#ifndef __DISTANCE_MAP_H__
#define __DISTANCE_MAP_H__

#include <Ghost.h>
#include <Board.h>
#include <BoardPosition.h>
#include <vector>
#include <Utils.h>

using namespace std;

class DistanceMap {

public:

	static function<vector<Utils::Orientation>()> walkableOrientations(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context);
	
	static function<Utils::Orientation()> orientationGoToTarget(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, const BoardPosition & target);
	
	static function<Utils::Orientation()> orientationAvoidTarget(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, const BoardPosition & target);

private:

	static vector<Utils::Orientation> walkableOrientations(const BoardPosition & position, const Board & board, const BoardSquare::GhostContext & context);
	
	static Utils::Orientation auxOrientatioGoToTarget(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, const BoardPosition & target);

};

#endif
