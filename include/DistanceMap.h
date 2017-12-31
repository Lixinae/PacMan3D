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

};

#endif
