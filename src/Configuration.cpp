#include <Configuration.h>

Configuration::Configuration(
		const map<control, SDLKey> &keyMap,
		const map<GameRepresentation::ModelType, AbstractModel3D *> &modelMap,
		int windowWidth,
		int windowHeight) :
		_keyMap(keyMap),
		_windowWidth(windowWidth),
		_windowHeight(windowHeight),
		_map_model3D(modelMap) {

}

Configuration Configuration::defaultConfiguration() {
	map<control, SDLKey> keyMap;
	keyMap[control::UP] = Utils::Utils::stringToKey("z");
	keyMap[control::DOWN] = Utils::stringToKey("s");
	keyMap[control::LEFT] = Utils::stringToKey("q");
	keyMap[control::RIGHT] = Utils::stringToKey("d");
	keyMap[control::CHANGE_CAMERA] = Utils::stringToKey("c");
	keyMap[control::PAUSE_GAME] = Utils::stringToKey("p");
	keyMap[control::SAVE_GAME] = Utils::stringToKey("o");
	keyMap[control::LOAD_GAME] = Utils::stringToKey("i");
	keyMap[control::EXIT] = Utils::stringToKey("k");
	keyMap[control::RESTART] = Utils::stringToKey("r");
	map<GameRepresentation::ModelType, AbstractModel3D *> modelMap; //TODO
	return Configuration(keyMap, modelMap, 800, 600);
}

map<control, SDLKey> Configuration::keyMapFromJSON(const json &json) {
	map<control, SDLKey> keyMap;
	keyMap[control::UP] = Utils::stringToKey(json["Up"]);
	keyMap[control::DOWN] = Utils::stringToKey(json["Down"]);
	keyMap[control::LEFT] = Utils::stringToKey(json["Left"]);
	keyMap[control::RIGHT] = Utils::stringToKey(json["Right"]);
	keyMap[control::CHANGE_CAMERA] = Utils::stringToKey(json["ChangeCamera"]);

	keyMap[control::PAUSE_GAME] = Utils::stringToKey("p");
	keyMap[control::SAVE_GAME] = Utils::stringToKey("o");
	keyMap[control::LOAD_GAME] = Utils::stringToKey("i");
	keyMap[control::EXIT] = Utils::stringToKey("k");
	keyMap[control::RESTART] = Utils::stringToKey("r");

//	keyMap[control::PAUSE_GAME] = Utils::stringToKey(json["Pause"]);
//	keyMap[control::SAVE_GAME] = Utils::stringToKey(json["Save"]);
//	keyMap[control::LOAD_GAME] = Utils::stringToKey(json["Load"]);
//	keyMap[control::EXIT] = Utils::stringToKey(json["Exit"]);
	return keyMap;
}

map<GameRepresentation::ModelType, AbstractModel3D *> Configuration::modelMapFromJSON(const json &jsonModels) {
	map<GameRepresentation::ModelType, AbstractModel3D *> modelMap;
	json modelsArray = jsonModels["models"];
	for (auto &it : modelsArray) {
		GameRepresentation::ModelType modelType = GameRepresentation::modelFromString(it["name"]);
		AbstractModel3D *model_3d = AbstractModel3D::fromJSON(it["model"]);
		modelMap[modelType] = model_3d;
	}
	return modelMap;
}

Configuration Configuration::fromJSON(const json &json) {
	map<control, SDLKey> keyMap = keyMapFromJSON(json["keybinds"]);
	map<GameRepresentation::ModelType, AbstractModel3D *> modelMap = modelMapFromJSON(json);
	int windowWidth = json["windowSize"]["width"];
	int windowHeight = json["windowSize"]["height"];
	return Configuration(keyMap, modelMap, windowWidth, windowHeight);
}


Configuration Configuration::fromJSONFile(const string &filePath) {
	json jsonConfig;
	ifstream configFile(filePath);
	configFile >> jsonConfig;
	configFile.close();
	return fromJSON(jsonConfig);
}

int Configuration::getWidth() const {
	return _windowWidth;
}

int Configuration::getHeight() const {
	return _windowHeight;
}

const map<control, SDLKey> Configuration::getControlMap() const {
	return _keyMap;
}

const map<GameRepresentation::ModelType, AbstractModel3D *> Configuration::getModelMap() const {
	return _map_model3D;
}


