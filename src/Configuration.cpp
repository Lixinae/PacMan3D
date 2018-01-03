#include <Configuration.h>

Configuration::Configuration(
		const map<control, SDLKey> &keyMap,
		const map<GameRepresentation::ModelType, function<AbstractModel3D *()>> &modelMap,
		int windowWidth,
		int windowHeight) :
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
	DirectionalLight *directionalLight = nullptr;
	// todo -> Changer quand il aura plus de lumiere
	if (lightArray[0]["type"] == "spot") {
		spotLight = SpotLight::fromJSON(lightArray[0]);
	} else if (lightArray[1]["type"] == "spot") {
		spotLight = SpotLight::fromJSON(lightArray[1]);
	}
	if (lightArray[1]["type"] == "directional") {
		directionalLight = DirectionalLight::fromJSON(lightArray[1]);
	} else if (lightArray[0]["type"] == "directional") {
		directionalLight = DirectionalLight::fromJSON(lightArray[0]);
	}
	for (auto &it : modelsArray) {
		GameRepresentation::ModelType modelType = GameRepresentation::modelFromString(it["name"]);
		function<AbstractModel3D *()> generator = [it, spotLight, directionalLight]() {
			return AbstractModel3D::fromJSON(it["model"], spotLight, directionalLight);
		};
		modelMap[modelType] = generator;
	}
	return modelMap;
}

Configuration Configuration::fromJSON(const json &json) {
	map<control, SDLKey> keyMap = keyMapFromJSON(json["keybinds"]);
	map<GameRepresentation::ModelType, function<AbstractModel3D *()>> modelMap = modelMapFromJSON(json);
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

const map<GameRepresentation::ModelType, function<AbstractModel3D *()>> Configuration::getModelMap() const {
	return _map_model3D;
}


