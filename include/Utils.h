#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <vector>
#include <map>
#include <glm/vec3.hpp>
#include <SDL/SDL_keysym.h>
#include <algorithm>

using namespace std;

class Utils {

public:

	enum class Orientation {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};

	static const string GAME_SAVE_FILE;

	/**
	 * Renvoie une orientation à partir de sa représentation en chaine de caractere
	 * @param strOrientation : representation en chaine de caractere de l'orientation
	 * @return l'orientation associé
	 */
	static Utils::Orientation orientationFromString(string strOrientation);

	/**
	 * Renvoie la représentation en chaine de caractere d'une orientation
	 * @param orientation : orientation
	 * @return la représentation en chaine de caractere d'une orientation
	 */
	static string orientationToString(Utils::Orientation orientation);

	/**
	 * Renvoie l'angle d'orientation d'une orientation
	 * @param orientation : orientation
	 * @return l'angle d'orientation
	 */
	static float degreesOfOrientation(Utils::Orientation orientation);

	/**
	 * Renvoie le vecteur associé à l'orientation
	 * @param orientation : orientation
	 * @return le vecteur de l'orientation
	 */
	static glm::vec3 vectorOfOrientation(Utils::Orientation orientation);

	/**
	 * Renvoie une orientation aléatoire
	 * @return une orientation aléatoire
	 */
	static Utils::Orientation randomOrientation();

	/**
	 * Renvoie une orientation aléatoire
	 * @param orientations : orientations disponibles
	 * @return une orientation aléatoire
	 */
	static Utils::Orientation randomOrientation(vector<Utils::Orientation> orientations);

	/**
	 * Renvoie l'orientation opposé
	 * @param orientation : orientation
	 * @return l'orientation opposé
	 */
	static Utils::Orientation oppositeOrientation(Utils::Orientation orientation);

	/**
	 * Renvoie une orientation relative à un point de vue
	 * @param viewOrientation : orientation du point de vue
	 * @param orientation : orientation
	 * @return l'orientation absolue
	 */
	static Utils::Orientation relativeOrientation(Utils::Orientation viewOrientation, Utils::Orientation orientation);

	/**
	 * Renvoie l'orientation de deux vecteurs
	 * @param a : vecteur a
	 * @param b : vecteur b
	 * @return l'orientation de deux vecteurs
	 */
	template<typename T>
	static vector<T> intersection(vector<T> a, vector<T> b) {
		vector<T> sa(a);
		vector<T> sb(b);
		vector<T> result;
		sort(sa.begin(), sa.end());
		sort(sb.begin(), sb.end());
		set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), back_inserter(result));
		return result;
	};

	/**
	 * Desalloue la memoire des valeurs du vecteur
	 * @param vecteur : vecteur a liberer
	 */
	template<typename T>
	static void cleanVector(vector<T *> vector) {
		for (T *value : vector) {
			delete value;
		}
	};

	/**
	 * Desalloue la memoire des valeurs d'une map
	 * @param map : map a liberer
	 */
	template<typename K, typename V>
	static void cleanMap(map<K, V *> map) {
		for (auto &entry : map) {
			delete entry.second;
		}
	};

	/**
	 * Renvoie une touche du clavier à partir de sa représentation en chaine de caractere
	 * @param s : representation en chaine de caractere de la touche du clavier
	 * @return la touche du clavier associé
	 */
	static SDLKey stringToKey(string s);

	/**
	 * Renvoie la représentation en chaine de caractere d'une touche du clavier
	 * @param touche du clavier : touche du clavier
	 * @return la représentation en chaine de caractere d'une touche du claviet
	 */
	static string keyToString(SDLKey key);

	/**
	 * Renvoie la majuscule d'une chaine de caractere
	 * @return la majuscule d'une chaine de caractere
	 */
	static string stringToUpper(string str);

private:

	Utils() = default;

};

#endif
