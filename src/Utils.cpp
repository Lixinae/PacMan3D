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
