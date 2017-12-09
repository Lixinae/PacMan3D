#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <iostream>
#include <map>
#include <json/json.hpp>

using json = nlohmann::json;

using namespace std;

enum class control {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    CHANGE_CAMERA
    // todo Add other possible controles if needed
};

class Configuration {

private:

    map<control, string> _keyMap; // TODO should be a control -> SDL_key map
    
    Configuration(map<control, string> keyMap);
    
    static map<control, string> keyMapFromJSON(const json & json);

public:

	static Configuration defaultConfiguration();
	
	static Configuration fromJSON(const json & json);
	static Configuration fromJSONFile(const string & filePath);

    map<control, string> getControlMap();
    
};

#endif

