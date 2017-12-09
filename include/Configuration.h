#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <iostream>
#include <map>
#include <json/json.hpp>
#include <SDL/SDL.h>

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

    map<control, SDLKey> _keyMap; // TODO should be a control -> SDL_key map
    
    Configuration(map<control, SDLKey> keyMap);
    
    static map<control, SDLKey> keyMapFromJSON(const json & json);

public:

	static Configuration defaultConfiguration();
	
	static Configuration fromJSON(const json & json);
	static Configuration fromJSONFile(const string & filePath);

    map<control, SDLKey> getControlMap();
    
};

#endif

