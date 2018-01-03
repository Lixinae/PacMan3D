#ifndef __BOARD_REPRESENTATION_H__
#define __BOARD_REPRESENTATION_H__

#include <BoardPosition.h>
#include <map>
#include <vector>
#include <Utils.h>

using namespace std;

class GameRepresentation {

public:

	enum class ModelType {

		PACMAN,
		GHOST_BLINKY,
		GHOST_PINKY,
		GHOST_INKY,
		GHOST_CLYDE,
		GHOST_WEAK,
		WALL,
		FLOOR,
		TUNNEL,
		DOOR,
		PAC_GOMME,
		SUPER_PAC_GOMME,
		FRUIT

	};

	struct Model {

		ModelType modelType;
		Utils::Orientation orientation;
		float shift;

		Model(ModelType modelType, Utils::Orientation orientation, float shift);

		Model(ModelType modelType);

	};

	struct ModelInformations {

		BoardPosition position;
		Utils::Orientation orientation;
		float shift;

		ModelInformations(const BoardPosition &position, Utils::Orientation orientation, float shift);

	};

	static vector<ModelType> MODELS;

	/**
	 * Créer un modele a partir de sa representation en chaine de caracteres
	 * @param strModel : la representation du modele en chaine de caracteres
	 * @return le modele
	 **/
	static ModelType modelFromString(const string &strModel);

	/**
	 * Construit une representation du jeu
	 **/
	GameRepresentation();

	/**
	 * Renvoie les informations du modele en argument
	 * @param modelType : le modele
	 * @return les informations
	 **/
	const vector<ModelInformations> &getInformations(ModelType modelType) const;

	/**
	 * Ajoute un modele a la representation
	 * @param model : le model
	 * @param position : la position
	 **/
	void add(Model model, const BoardPosition &position);

	/**
	 * Supprime un modele de la representation
	 * @param model : le model
	 * @param position : la position
	 **/
	void remove(Model model, const BoardPosition &position);

	/**
	 * Renvoie les informations du modele en argument
	 * @param modelType : le modele
	 * @return les informations
	 **/
	const vector<ModelInformations> &operator[](ModelType modelType) const;

private:

	map<ModelType, vector<ModelInformations>> _modelsPositions;

	static vector<ModelType> buildVector();
};

#endif
