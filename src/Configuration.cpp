#include <Configuration.h>

Configuration::Configuration(
	const map<control, SDLKey> &keyMap,
	const map<GameRepresentation::Model, AbstractModel3D *> &modelMap,
	int windowWidth,
	int windowHeight):
        _keyMap(keyMap),
        _windowWidth(windowWidth),
        _windowHeight(windowHeight),
        _map_model3D(modelMap) 
{

}

Configuration Configuration::defaultConfiguration() {
    map<control, SDLKey> keyMap;
    keyMap[control::UP] = stringToKey("z");
    keyMap[control::DOWN] = stringToKey("s");
    keyMap[control::LEFT] = stringToKey("q");
    keyMap[control::RIGHT] = stringToKey("d");
    keyMap[control::CHANGE_CAMERA] = stringToKey("c");
    keyMap[control::ZOOM_IN] = stringToKey("b");
    keyMap[control::ZOOM_OUT] = stringToKey("n");
    map<GameRepresentation::Model, AbstractModel3D *> modelMap;
    return Configuration(keyMap, modelMap, 800, 600);
}

map<control, SDLKey> Configuration::keyMapFromJSON(const json &json) {
    map<control, SDLKey> keyMap;
    keyMap[control::UP] = stringToKey(json["Up"]);
    keyMap[control::DOWN] = stringToKey(json["Down"]);
    keyMap[control::LEFT] = stringToKey(json["Left"]);
    keyMap[control::RIGHT] = stringToKey(json["Right"]);
    keyMap[control::CHANGE_CAMERA] = stringToKey(json["ChangeCamera"]);
    keyMap[control::ZOOM_IN] = stringToKey(json["ZoomIn"]);
    keyMap[control::ZOOM_OUT] = stringToKey(json["ZoomOut"]);
    return keyMap;
}

map<GameRepresentation::Model, AbstractModel3D *> Configuration::modelMapFromJSON(const json &jsonModels) {
    map<GameRepresentation::Model, AbstractModel3D *> modelMap;
    json modelsArray = jsonModels["models"];
    for (auto & it : modelsArray) {
		GameRepresentation::Model model = GameRepresentation::modelFromString(it["name"]);
		AbstractModel3D * model_3d = AbstractModel3D::fromJSON(it["model"]);
		modelMap[model] = model_3d;
    }
    return modelMap;
}

AbstractModel3D *Configuration::modelFromJSON(const json &json) {

    mat4 modelTransform(1);
    modelTransform = scale(modelTransform, vec3(json["scale"]["x"], json["scale"]["y"], json["scale"]["z"]));
    //modelTransform = rotate(modelTransform,vec3(json["rotate"]["x"], json["rotate"]["y"], json["rotate"]["z"]));
    //modelTransform = translate(modelTransform,vec3(json["translate"]["x"], json["translate"]["y"], json["translate"]["z"]));
    string s = json["objPath"];
    string s1 = json["texPath"];
    cout << s << endl;
    cout << s1 << endl;
    // todo -> Segfault sans raison
    AbstractModel3D *model3D = new TexModel3D(json["objPath"], json["texPath"], modelTransform);
    cout << "fuuuu" << endl;
    return model3D;
}

Configuration Configuration::fromJSON(const json &json) {
    map<control, SDLKey> keyMap = keyMapFromJSON(json["keybinds"]);
	map<GameRepresentation::Model, AbstractModel3D *> modelMap = modelMapFromJSON(json);
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

const map<GameRepresentation::Model, AbstractModel3D *> Configuration::getModelMap() const {
    return _map_model3D;
}

SDLKey Configuration::stringToKey(string s) {
    if (s == "a") return SDLK_a;
    if (s == "b") return SDLK_b;
    if (s == "c") return SDLK_c;
    if (s == "d") return SDLK_d;
    if (s == "e") return SDLK_e;
    if (s == "f") return SDLK_f;
    if (s == "g") return SDLK_g;
    if (s == "h") return SDLK_h;
    if (s == "i") return SDLK_i;
    if (s == "j") return SDLK_j;
    if (s == "k") return SDLK_k;
    if (s == "l") return SDLK_l;
    if (s == "m") return SDLK_m;
    if (s == "n") return SDLK_n;
    if (s == "o") return SDLK_o;
    if (s == "p") return SDLK_p;
    if (s == "q") return SDLK_q;
    if (s == "r") return SDLK_r;
    if (s == "s") return SDLK_s;
    if (s == "t") return SDLK_t;
    if (s == "u") return SDLK_u;
    if (s == "v") return SDLK_v;
    if (s == "w") return SDLK_w;
    if (s == "x") return SDLK_x;
    if (s == "y") return SDLK_y;
    if (s == "z") return SDLK_z;
    if (s == "1") return SDLK_1;
    if (s == "2") return SDLK_2;
    if (s == "3") return SDLK_3;
    if (s == "4") return SDLK_4;
    if (s == "5") return SDLK_5;
    if (s == "6") return SDLK_6;
    if (s == "7") return SDLK_7;
    if (s == "8") return SDLK_8;
    if (s == "9") return SDLK_9;
    if (s == "0") return SDLK_0;
    if (s == "k+") return SDLK_KP_PLUS;
    if (s == "k-") return SDLK_KP_MINUS;
    if (s == "k*") return SDLK_KP_MULTIPLY;
    if (s == "k/") return SDLK_KP_DIVIDE;
    if (s == "kenter") return SDLK_KP_ENTER;
    if (s == "k.") return SDLK_KP_PERIOD;
    if (s == "insert") return SDLK_INSERT;
    if (s == "home") return SDLK_HOME;
    if (s == "pgup") return SDLK_PAGEUP;
    if (s == "pgdown") return SDLK_PAGEDOWN;
    if (s == "end") return SDLK_END;
    if (s == "delete") return SDLK_DELETE;
    if (s == "ralt") return SDLK_RALT;
    if (s == "rshift") return SDLK_RSHIFT;
    if (s == "rctrl") return SDLK_RCTRL;
    if (s == "lalt") return SDLK_LALT;
    if (s == "lshift") return SDLK_LSHIFT;
    if (s == "lctrl") return SDLK_LCTRL;
    if (s == "up") return SDLK_UP;
    if (s == "down") return SDLK_DOWN;
    if (s == "right") return SDLK_RIGHT;
    if (s == "left") return SDLK_LEFT;
    if (s == "`") return SDLK_BACKQUOTE;
    if (s == "[") return SDLK_LEFTBRACKET;
    if (s == "]") return SDLK_RIGHTBRACKET;
    if (s == "-") return SDLK_MINUS;
    if (s == "=") return SDLK_EQUALS;
    if (s == "backspace") return SDLK_BACKSPACE;
    if (s == "/") return SDLK_SLASH;
    if (s == "\\") return SDLK_BACKSLASH;
    if (s == ",") return SDLK_COMMA;
    if (s == ".") return SDLK_PERIOD;
    if (s == ";") return SDLK_SEMICOLON;
    if (s == "'") return SDLK_QUOTE;
    if (s == "f1") return SDLK_F1;
    if (s == "f2") return SDLK_F2;
    if (s == "f3") return SDLK_F3;
    if (s == "f4") return SDLK_F4;
    if (s == "f5") return SDLK_F5;
    if (s == "f6") return SDLK_F6;
    if (s == "f7") return SDLK_F7;
    if (s == "f8") return SDLK_F8;
    if (s == "f9") return SDLK_F9;
    if (s == "f10") return SDLK_F10;
    if (s == "f11") return SDLK_F11;
    if (s == "f12") return SDLK_F12;
    if (s == "f13") return SDLK_F13;
    if (s == "f14") return SDLK_F14;
    if (s == "f15") return SDLK_F15;
    if (s == "esc") return SDLK_ESCAPE;
}
