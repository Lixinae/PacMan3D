#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <iostream>
#include <map>
#include <json/json.hpp>
#include <SDL/SDL.h>
#include <GameRepresentation.h>
#include <AbstractModel3D.h>
#include <fstream>
#include <TexModel3D.h>

using json = nlohmann::json;

using namespace std;

enum class control {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	CHANGE_CAMERA,
	ZOOM_IN,
	ZOOM_OUT,
	PAUSE_GAME,
	SAVE_GAME,
	LOAD_GAME,
	EXIT
	// todo Add other possible controles if needed
};

class Configuration {

private:

	Configuration(
			const map<control, SDLKey> &keyMap,
			const map<GameRepresentation::ModelType, AbstractModel3D *> &modelMap,
			int windowWidth,
			int windowHeight
	);

	map<control, SDLKey> _keyMap;
	map<GameRepresentation::ModelType, AbstractModel3D *> _map_model3D;
	int _windowWidth;
	int _windowHeight;

	static map<control, SDLKey> keyMapFromJSON(const json &json);

	static map<GameRepresentation::ModelType, AbstractModel3D *> modelMapFromJSON(const json &json);

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
	static Configuration fromJSONFile(const string &filePath);

	const map<control, SDLKey> getControlMap() const;

	const map<GameRepresentation::ModelType, AbstractModel3D *> getModelMap() const;

	int getWidth() const;

	int getHeight() const;

};

#endif

