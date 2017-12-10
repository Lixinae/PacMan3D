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
    CHANGE_CAMERA,
	ZOOM_IN,
	ZOOM_OUT
    // todo Add other possible controles if needed
};

class Configuration {

private:

    Configuration(map<control, SDLKey> keyMap, pair<int, int> windowSize);

    map<control, SDLKey> _keyMap;
    pair<int, int> _windowSize;

    static SDLKey stringToKey(string s);
    
    static map<control, SDLKey> keyMapFromJSON(const json & json);

    static pair<int, int> windowSizeFromJson(const json &json);

    static Configuration fromJSON(const json &json);
public:

    /**
     * Charge la configuration par default de l'application
     * @return La configuration par default de l'application
     */
    static Configuration defaultConfiguration();

    /**
     * Charge la configuration contenu dans le fichier json donné en argument
     * @param filePath : Chemin vers le fichier json de la configuration
     * @return La configuration lu à partir du fichier json
     */
	static Configuration fromJSONFile(const string & filePath);


    map<control, SDLKey> getControlMap() const;

    int getWidth() const;

    int getHeight() const;

    pair<int, int> get_windowSize() const;

};

#endif

