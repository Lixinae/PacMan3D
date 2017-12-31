#include <DistanceMap.h>

function<vector<Utils::Orientation>()> DistanceMap::walkableOrientations(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context) {
	return [&]() {
		vector<Utils::Orientation> orientations = {
			Utils::Orientation::NORTH,
			Utils::Orientation::SOUTH,
			Utils::Orientation::EAST,
			Utils::Orientation::WEST
		};
		vector<Utils::Orientation> walkable;
		for (Utils::Orientation orientation : orientations) {
			BoardSquare *square = board[ghost.getPosition().translate(orientation)];
			if (square != nullptr && square->isGhostWalkable(context)) {
				walkable.push_back(orientation);
			}
		}
		return walkable;
	};
}
