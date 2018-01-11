#ifndef __PACMAN_H__
#define __PACMAN_H__

#include <BoardPosition.h>
#include <GameRepresentation.h>
#include <json/json.hpp>
#include <Utils.h>

using json = nlohmann::json;

class Pacman {

public:

	static int MAX_ITERATION;

	/**
	 * Créer pacman à partir de sa représentation en JSON
	 * @param jsonGhost : représentation en JSON de pacman
	 * @return le pacman crée
	 */
	static Pacman fromJSON(const json &jsonPacman);

	/**
	 * Renvoie l'orientation de pacman
	 * @return l'orientation de pacman
	 */
	Utils::Orientation getOrientation() const;

	/** 
	 * Change l'orientation de pacman
	 * @param orientation : la nouvelle orientation de pacman
	 */
	void setOrientation(Utils::Orientation orientation);

	/**
	 * Change la prochaine orientation de pacman
	 * @param orientation : la prochaine orientation de pacman
	 */
	bool orientTo(Utils::Orientation orientation);

	/**
	 * Renvoie la position de pacman
	 * @return la position de pacman
	 */
	BoardPosition getPosition() const;

	/** 
	 * Change la position de pacman
	 * @param position : la nouvelle position de pacman
	 */
	void setPosition(const BoardPosition &position);

	/**
	 * Renvoie les positions ou pacman appartient graphiquement
	 * @return les potitions graphiques de pacman
	 */
	vector<BoardPosition> getGraphicalPositions() const;

	/**
	 * Change la prochaine position de pacman
	 * @param position : la nouvelle position de pacman
	 * @return true si pacman a bougé, false sinon
	 */
	bool goTo(const BoardPosition &position);

	/**
	 * Renvoie le decalage graphique par rapport au centre de la case
	 * @return le decalage graphique par rapport au centre de la case
	 */
	float getShift() const;

	/**
	 * Itere pacman
	 **/
	void iterate();

	/**
	 * Renvoie le modele de pacman
	 * @return le modele de pacman
	 */
	GameRepresentation::Model getModel() const;

	/**
	 * Convertit pacman en JSON
	 * @return la représentation de pacman en JSON
	 **/
	json toJSON() const;

private:

	BoardPosition _position;
	Utils::Orientation _orientation;
	BoardPosition _nextPosition;
	int _iterPosition;
	int _iterOrientation;

	Pacman(const BoardPosition &position, Utils::Orientation orientation);

};

#endif
