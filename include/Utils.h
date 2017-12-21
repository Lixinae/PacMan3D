#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>

using namespace std;

class Utils {

public:

	enum class Orientation {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};
	
	static const string SHADER_PATH;
	
	static Utils::Orientation orientationFromString(string strOrientation);

	static float degreesOfOrientation(Utils::Orientation orientation);
	
	static Utils::Orientation randomOrientation();

private:

	Utils() = default;

};

#endif
