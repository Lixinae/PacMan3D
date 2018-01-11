#ifndef __BOARD_SQUARE_H__
#define __BOARD_SQUARE_H__

#include <Pacman.h>
#include <Ghost.h>
#include <GameInformations.h>
#include <GameRepresentation.h>
#include <vector>
#include <json/json.hpp>

using json = nlohmann::json;

class BoardSquare {

public:

	struct PacmanContext {

		Pacman &pacman;
		vector<Ghost *> &ghosts;
		GameInformations &informations;

		PacmanContext(Pacman &pacman, vector<Ghost *> &ghosts, GameInformations &informations);

	};

	struct GhostContext {

		Ghost &ghost;

		explicit GhostContext(Ghost &ghost);

	};

	/**
	 * Créer une case à partir de sa representation en JSON
	 * La case est allouée dynamiquement avec l'opérateur new
	 * @param jsonSquare : la representation en JSON de la case
	 * @return la case crée
	 **/
	static BoardSquare *fromJSON(const json &jsonSquare);

	/**
	 * Renvoie les modeles de la case
	 * @return les modeles de la case
	 **/
	virtual vector<GameRepresentation::Model> getModels() const = 0;

	/**
	 * Teste si la case est franchissable par pacman
	 * @param context : contexte
	 * @return true si la case est franchissable, false sinon
	 **/
	virtual bool isPacmanWalkable(const PacmanContext &context) const = 0;

	/**
	 * Fait recevoir pacman sur la case
	 * @param context : context
	 **/
	virtual void receivePacman(PacmanContext &context) = 0;

	/**
	 * Teste si la case est franchissable par un fantome
	 * @param context : contexte
	 * @return true si la case est franchissable, false sinon
	 **/
	virtual bool isGhostWalkable(const GhostContext &context) const = 0;

	/**
	 * Fait recevoir pacman sur la case
	 * @param context : context
	 **/
	virtual void receiveGhost(GhostContext &context) = 0;

	/**
	 * Teste si une action doit encore etre réalisée sur la case pour que le jeu se termine
	 * @return true si l'action a été réalisée sur la case, false sinon
	 **/
	virtual bool isDone() const = 0;

	/**
	 * Itere la case
	 **/
	virtual void iterate() = 0;

	/**
	 * Renvoie la position du voisin de la case
	 * @param position : position de la case
	 * @param orientation : orientation pour le prochain voisin
	 * @return position sur prochain voisin
	 **/
	virtual BoardPosition neighbour(const BoardPosition &position, Utils::Orientation orientation);

	/**
	 * Copie la case
	 * @return une copie de la case
	 **/
	virtual BoardSquare *clone() const = 0;

	/**
	 * Renvoie la représentation en JSON de la case
	 * @return la représentation en JSON de la case
	 **/
	virtual json toJSON() const = 0;

	/**
	 * Destructeur
	 **/
	virtual ~BoardSquare() = default;

};

#endif
