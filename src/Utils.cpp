#include <Utils.h>

using namespace std;

const string Utils::SHADER_PATH = "shaders";

Utils::Orientation Utils::orientationFromString(string strOrientation) {
	if (strOrientation == "north") {
		return Utils::Orientation::NORTH;
	}
	if (strOrientation == "south") {
		return Utils::Orientation::SOUTH;
	}
	if (strOrientation == "east") {
		return Utils::Orientation::EAST;
	}
	if (strOrientation == "west") {
		return Utils::Orientation::WEST;
	}
	throw invalid_argument(strOrientation + " is not a valid string representation of orientation");
}

float Utils::degreesOfOrientation(Utils::Orientation orientation) {
	switch (orientation) {
		case Utils::Orientation::NORTH:
			return 180;
		case Utils::Orientation::SOUTH:
			return 0;
		case Utils::Orientation::EAST:
			return 90;
		case Utils::Orientation::WEST:
			return -90;
	}
}

Utils::Orientation Utils::randomOrientation(vector<Utils::Orientation> orientations) {
	return orientations[rand() % orientations.size()];
}

Utils::Orientation Utils::randomOrientation() {
	return randomOrientation({
		Utils::Orientation::NORTH,
		Utils::Orientation::SOUTH,
		Utils::Orientation::EAST,
		Utils::Orientation::WEST
	});
}

Utils::Orientation Utils::oppositeOrientation(Utils::Orientation orientation) {
	switch (orientation) {
		case Utils::Orientation::NORTH:
			return Utils::Orientation::SOUTH;
		case Utils::Orientation::SOUTH:
			return Utils::Orientation::NORTH;
		case Utils::Orientation::EAST:
			return Utils::Orientation::WEST;
		case Utils::Orientation::WEST:
			return Utils::Orientation::EAST;
	}
}

Utils::Orientation Utils::relativeOrientation(Utils::Orientation viewOrientation, Utils::Orientation orientation) {
	vector<Utils::Orientation> orientations = {
			Utils::Orientation::NORTH,
			Utils::Orientation::WEST,
			Utils::Orientation::SOUTH,
			Utils::Orientation::EAST
	};
	int viewOrientationIndex, orientationIndex;
	switch (viewOrientation) {
		case Utils::Orientation::NORTH:
			viewOrientationIndex = 0;
			break;
		case Utils::Orientation::SOUTH:
			viewOrientationIndex = 2;
			break;
		case Utils::Orientation::EAST:
			viewOrientationIndex = 3;
			break;
		case Utils::Orientation::WEST:
			viewOrientationIndex = 1;
			break;
	}
	switch (orientation) {
		case Utils::Orientation::NORTH:
			orientationIndex = 0;
			break;
		case Utils::Orientation::SOUTH:
			orientationIndex = 2;
			break;
		case Utils::Orientation::EAST:
			orientationIndex = 3;
			break;
		case Utils::Orientation::WEST:
			orientationIndex = 1;
			break;
	}
	return orientations[(viewOrientationIndex + orientationIndex) % orientations.size()];
}
