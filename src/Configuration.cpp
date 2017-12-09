#include <Configuration.h>
#include <fstream>

Configuration::Configuration() {

}


Configuration::Configuration(const string &filePath) : _filePath(filePath) {
    if (!readConfigFromFile()) {
        loadDefaultConfiguration();
    }
}

bool Configuration::readConfigFromFile() {
    cout << "Loading config file" << endl;
    json jsonConfig;
    ifstream configFile(_filePath);
    configFile >> jsonConfig;
    configFile.close();
    return parseJsonKeybinds(jsonConfig["keybinds"]);
}

bool Configuration::parseJsonKeybinds(const json &json) {
    try {
        pair<control, string> keyUp(control::UP, json["Up"]);
        pair<control, string> keyDown(control::DOWN, json["Down"]);
        pair<control, string> keyLeft(control::LEFT, json["Left"]);
        pair<control, string> keyRight(control::RIGHT, json["Right"]);
        pair<control, string> keyChangeCamera(control::CHANGE_CAMERA, json["ChangeCamera"]);
        _keyMap.insert(keyUp);
        _keyMap.insert(keyDown);
        _keyMap.insert(keyLeft);
        _keyMap.insert(keyRight);
        _keyMap.insert(keyChangeCamera);
    } catch (const exception &e) {
        return false;
    }
    return true;
}

void Configuration::loadDefaultConfiguration() {
    pair<control, string> keyUp(control::UP, "z");
    pair<control, string> keyDown(control::DOWN, "s");
    pair<control, string> keyLeft(control::LEFT, "q");
    pair<control, string> keyRight(control::RIGHT, "d");
    pair<control, string> keyChangeCamera(control::CHANGE_CAMERA, "c");
    _keyMap.insert(keyUp);
    _keyMap.insert(keyDown);
    _keyMap.insert(keyLeft);
    _keyMap.insert(keyRight);
    _keyMap.insert(keyChangeCamera);
}

map<control, string> Configuration::getControlMap() {
    return _keyMap;
}

