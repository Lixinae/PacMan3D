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
	PAUSE_GAME,
	SAVE_GAME,
	LOAD_GAME,
	EXIT,
	RESTART
};

class Configuration {

private:

	Configuration(
			const map<control, SDLKey> &keyMap,
			const map<GameRepresentation::ModelType, function<AbstractModel3D *()>> &modelMap,
			uint32_t windowWidth,
			uint32_t windowHeight
	);

	map<control, SDLKey> _keyMap;
	map<GameRepresentation::ModelType, function<AbstractModel3D *()>> _map_model3D;
	uint32_t _windowWidth;
	uint32_t _windowHeight;

	static map<control, SDLKey> keyMapFromJSON(const json &json);

	static map<GameRepresentation::ModelType, function<AbstractModel3D *()>> modelMapFromJSON(const json &json);

	static Configuration fromJSON(const json &json);

public:


	/**
	 * Charge la configuration contenu dans le fichier json donné en argument
	 * @param filePath : Chemin vers le fichier json de la configuration
	 * @return La configuration lu à partir du fichier json
	 */
	static Configuration fromJSONFile(const string &filePath);

	/**
	 * Renvoie le tableau des controles
	 * @return le tableau des controles
	 **/
	const map<control, SDLKey> getControlMap() const;

	/**
	 * Renvoie les generateurs pour les modeles abstraits 3D
	 * @return les generateurs pour les modeles abstraits 3D
	 **/
	const map<GameRepresentation::ModelType, function<AbstractModel3D *()>> getModelMap() const;

	/**
	 * Renvoie la largeur de la fenetre
	 * @return la largeur de la fenetre
	 **/
	uint32_t getWidth() const;

	/**
	 * Renvoie la hauteur de la fenetre
	 * @return la hauteur de la fenetre
	 **/
	uint32_t getHeight() const;

};

#endif

