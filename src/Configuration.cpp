#include <Configuration.h>

Configuration::Configuration(
		const map<control, SDLKey> &keyMap,
		const map<GameRepresentation::ModelType, function<AbstractModel3D *()>> &modelMap,
		uint32_t windowWidth,
		uint32_t windowHeight) :
		_keyMap(keyMap),
		_windowWidth(windowWidth),
		_windowHeight(windowHeight),
		_map_model3D(modelMap) {

}

map<control, SDLKey> Configuration::keyMapFromJSON(const json &json) {
	map<control, SDLKey> keyMap;
	keyMap[control::UP] = Utils::stringToKey(json["Up"]);
	keyMap[control::DOWN] = Utils::stringToKey(json["Down"]);
	keyMap[control::LEFT] = Utils::stringToKey(json["Left"]);
	keyMap[control::RIGHT] = Utils::stringToKey(json["Right"]);
	keyMap[control::CHANGE_CAMERA] = Utils::stringToKey(json["ChangeCamera"]);
	keyMap[control::PAUSE_GAME] = SDLK_ESCAPE;
	keyMap[control::SAVE_GAME] = SDLK_o;
	keyMap[control::LOAD_GAME] = SDLK_i;
	keyMap[control::EXIT] = SDLK_k;
	keyMap[control::RESTART] = SDLK_r;
	return keyMap;
}

map<GameRepresentation::ModelType, function<AbstractModel3D *()>> Configuration::modelMapFromJSON(const json &jsonModels) {
	map<GameRepresentation::ModelType, function<AbstractModel3D *()>> modelMap;
	json modelsArray = jsonModels["models"];
	json lightArray = jsonModels["lights"];

	SpotLight *spotLight = nullptr;
	SpotLight *spotLightCamera = nullptr;
	if (lightArray[0]["type"] == "spot") {
		spotLight = SpotLight::fromJSON(lightArray[0]);
	}
	if (lightArray[1]["type"] == "spot") {
		spotLightCamera = SpotLight::fromJSON(lightArray[1]);
	}
	for (auto &it : modelsArray) {
		GameRepresentation::ModelType modelType = GameRepresentation::modelFromString(it["name"]);
		function<AbstractModel3D *()> generator = [it, spotLight, spotLightCamera]() {
			return AbstractModel3D::fromJSON(it["model"], spotLight, spotLightCamera);
		};
		modelMap[modelType] = generator;
	}
	return modelMap;
}

Configuration Configuration::fromJSON(const json &json) {
	map<control, SDLKey> keyMap = keyMapFromJSON(json["keybinds"]);
	map<GameRepresentation::ModelType, function<AbstractModel3D *()>> modelMap = modelMapFromJSON(json);
	uint32_t windowWidth = json["windowSize"]["width"];
	uint32_t windowHeight = json["windowSize"]["height"];
	return Configuration(keyMap, modelMap, windowWidth, windowHeight);
}


Configuration Configuration::fromJSONFile(const string &filePath) {
	json jsonConfig;
	ifstream configFile(filePath);
	configFile >> jsonConfig;
	configFile.close();
	return fromJSON(jsonConfig);
}

uint32_t Configuration::getWidth() const {
	return _windowWidth;
}

uint32_t Configuration::getHeight() const {
	return _windowHeight;
}

const map<control, SDLKey> Configuration::getControlMap() const {
	return _keyMap;
}

const map<GameRepresentation::ModelType, function<AbstractModel3D *()>> Configuration::getModelMap() const {
	return _map_model3D;
}


