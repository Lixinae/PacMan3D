#include <Configuration.h>
#include <fstream>

Configuration::Configuration(map<control, string> keyMap) : _keyMap(keyMap) {

}

Configuration Configuration::defaultConfiguration() {
	map<control, string> keyMap;
	keyMap[control::UP] = "z";
    keyMap[control::DOWN] = "s";
    keyMap[control::LEFT] = "q";
    keyMap[control::RIGHT] = "d";
    keyMap[control::CHANGE_CAMERA] = "c";
	return Configuration(keyMap);
}

map<control, string> Configuration::keyMapFromJSON(const json & json) {
	map<control, string> keyMap;
	keyMap[control::UP] = json["Up"];
    keyMap[control::DOWN] = json["Down"];
    keyMap[control::LEFT] = json["Left"];
    keyMap[control::RIGHT] = json["Right"];
    keyMap[control::CHANGE_CAMERA] = json["ChangeCamera"];
	return keyMap;
}

Configuration Configuration::fromJSON(const json & json) {
	map<control, string> keyMap = keyMapFromJSON(json["keybinds"]);
	return Configuration(keyMap);
}

Configuration Configuration::fromJSONFile(const string & filePath) {
	json jsonConfig;
	ifstream configFile(filePath);
	configFile >> jsonConfig;
    configFile.close();
	return fromJSON(jsonConfig);
}

map<control, string> Configuration::getControlMap() {
    return _keyMap;
}

