#include <DistanceMap.h>

#include <set>
#include <map>

using namespace std;

vector<Utils::Orientation> DistanceMap::walkableOrientations(const BoardPosition & position, const Board & board, const BoardSquare::GhostContext & context) {
	vector<Utils::Orientation> orientations = {
		Utils::Orientation::NORTH,
		Utils::Orientation::SOUTH,
		Utils::Orientation::EAST,
		Utils::Orientation::WEST
	};
	vector<Utils::Orientation> walkable;
	for (Utils::Orientation orientation : orientations) {
		BoardPosition neighbour = board[position]->neighbour(position, orientation);
		BoardSquare *square = board[neighbour];
		if (square != nullptr && square->isGhostWalkable(context)) {
			walkable.push_back(orientation);
		}
	}
	return walkable;
}

function<vector<Utils::Orientation>()> DistanceMap::walkableOrientations(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context) {
	return [&]() {
		return walkableOrientations(ghost.getPosition(), board, context);
	};
}

Utils::Orientation DistanceMap::auxOrientatioGoToTarget(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, const BoardPosition & target) {
	//Initialization
	BoardPosition initPosition = ghost.getPosition();
	vector<Utils::Orientation> walkable = DistanceMap::walkableOrientations(initPosition, board, context);
	map<BoardPosition, Utils::Orientation> originalOrientation;
	set<BoardPosition> currentPositions;
	for (Utils::Orientation orientation : walkable) {
		BoardPosition neighbour = board[initPosition]->neighbour(initPosition, orientation);
		if (neighbour == target) { // if target is a neighbour
			return orientation;
		}
		BoardSquare *square = board[neighbour];
		if (square != nullptr && square->isGhostWalkable(context)) {
			originalOrientation[neighbour] = orientation;
			currentPositions.insert(neighbour);
		}
	}
	set<BoardPosition> previousPositions = {initPosition};
	set<BoardPosition> nextPositions;
	// find direct for the target
	while (true) {
		for (BoardPosition position : currentPositions) {
			walkable = DistanceMap::walkableOrientations(position, board, context);
			//cerr << position << endl;
			for (Utils::Orientation orientation : walkable) {
				BoardPosition neighbour = board[position]->neighbour(position, orientation);
				if (previousPositions.find(neighbour) != previousPositions.end() || nextPositions.find(neighbour) != nextPositions.end()) {
					continue;
				}
				if (neighbour == target) { // if target is a neighbour
					return originalOrientation[position];
				}
				BoardSquare *square = board[neighbour];
				if (square != nullptr && square->isGhostWalkable(context)) {
					originalOrientation[neighbour] = originalOrientation[position];
					nextPositions.insert(neighbour);

				}
			}
		}
		if (nextPositions.size() == 0) {
			break;
		}
		previousPositions = currentPositions;
		currentPositions = nextPositions;
		nextPositions.clear();
	}
	// random position if target can not be reached
	return Utils::randomOrientation(DistanceMap::walkableOrientations(ghost.getPosition(), board, context));
}

function<Utils::Orientation()> DistanceMap::orientationGoToTarget(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, const BoardPosition & target) {
	return [&]() {
		return auxOrientatioGoToTarget(ghost, board, context, target);
	};
}

function<Utils::Orientation()> DistanceMap::orientationAvoidTarget(const Ghost & ghost, const Board & board, const BoardSquare::GhostContext & context, const BoardPosition & target) {
	return [&]() {
		return Utils::randomOrientation(DistanceMap::walkableOrientations(ghost, board, context)());
	};
}

