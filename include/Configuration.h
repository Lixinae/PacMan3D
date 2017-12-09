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
    map<control, string> _keyMap;
    string _filePath;

    bool parseJsonKeybinds(const json &json);

    bool readConfigFromFile();

    void loadDefaultConfiguration();

public:
    Configuration();

    Configuration(const string &filePath);

    map<control, string> getControlMap();
};

#endif

