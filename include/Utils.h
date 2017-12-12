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

private:

	Utils() = default;

};

#endif
