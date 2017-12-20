#include <Utils.h>

#include <stdexcept>

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
			return 0;
		case Utils::Orientation::SOUTH:
			return 180;
		case Utils::Orientation::EAST:
			return -90;
		case Utils::Orientation::WEST:
			return 90;
	}
}
